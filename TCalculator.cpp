#include "stdafix.h"
#include"math.h"
#include"TCalculator.h"

int TCalculator::priority(char ch)
{
	if (ch == '(') return 0;
	if (ch == '+' || ch == '-') return 1;
	if (ch == '*' ||ch == '/' || ch == '%') return 2;
	if (ch == '^') return 3;
	if (ch == 'c'||ch == 'l' || ch == 's' || ch == 'g'|| ch == 't') return 4;
}

TCalculator::TCalculator()
{
	infix = " ";
	postfix = " ";
}
TCalculator::~TCalculator()
{}
void TCalculator::topostfix()

{
	postfix = "";
	StC.Clr();
	StD.Clr();
	string tmp = "(";

	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == 'l' && infix[i + 1] == 'n')
		{
			tmp+= 'l';
			i++;
		}
		else if (infix[i] == 's' && infix[i + 1] == 'i' && infix[i+2] =='n')
		{
			tmp += 's';
			i += 2;
		}
		else if (infix[i] == 'c' && infix[i + 1] == 'o' && infix[i + 2] == 's')
		{
			tmp += 'c';
			i+=2;
		}
		else if (infix[i] == 't' && infix[i + 1] == 'a' && infix[i + 2] == 'n')
		{
			tmp += 't';
			i+=2;
		}
		else if (infix[i] == 'c' && infix[i + 1] == 't' && infix[i + 2] == 'g')
		{
			tmp += 'g';
			i+=2;
		}
		else if (infix[i] == 't' || infix[i] == 'g' || infix[i] == 'l' || infix[i] == 'c' || infix[i] == 's'|| infix[i] == '_' ){}
		else tmp += infix[i];

	}
	tmp += ')';
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '-' && tmp[i - 1] == '('&&tmp[i] != '(') 	postfix += "_";

		else if (((tmp[i] >= '0') && (tmp[i]) <= '9') || (tmp[i] == '.'))
			postfix += tmp[i];
		
		else if (tmp[i] == 'e') postfix += "2.71";
						
		else if (tmp[i] == 'p' && tmp[i + 1] == 'i')
		{
			postfix += "3.14";
			i++;
		}
		
		else if (tmp[i] == '(') StC.Push('(');

		else if (tmp[i] == ')') 
			{
				while (StC.Top() != 40) postfix += StC.Pop();
				StC.Pop();
			}

		else if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') || (tmp[i] == '/') || (tmp[i] == '%') || (tmp[i] == '^') || tmp[i] == 'c' || tmp[i] == 'l' || tmp[i] == 's' || tmp[i] == 'g' || tmp[i] == 't')
			{
				postfix += " ";
				while (priority(StC.Top()) >= priority(tmp[i]))
				postfix += StC.Pop();
				StC.Push(tmp[i]);
			}
	}
}

bool TCalculator::IsCorrect()
{
	if (infix[infix.size()-1] == '+' || infix[infix.size()-1] == '-' || infix[infix.size()-1] == '/' || infix[infix.size()-1] == '*' || infix[infix.size()-1] == '%' || infix[infix.size()-1] == '^') return 0;
	if (infix[0] == '+' || infix[0] == '-' || infix[0] == '/' || infix[0] == '*' || infix[0] == '%' || infix[0] == '^') return 0;
	TStack<char> sk;
	for (int i = 0; i < infix.size()-1; i++)
		if ((infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '%' || infix[i] == '*' || infix[i] == '^') && (infix[i+1] == '+' || infix[i+1] == '-' || infix[i+1] == '/' || infix[i+1] == '%' || infix[i+1] == '*' || infix[i+1] == '^'))
				return 0;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(') sk.Push('(');
		else if (sk.IsEmpty() && infix[i] == ')') return false;
		else if (infix[i] == ')') 	sk.Pop();
			
	}
	return (sk.IsEmpty());
}

double TCalculator::Calc()
{
	StD.Clr();
	double first, second, res;

	for (int i = 0; i < postfix.size(); i++)
	{
		
		if ((postfix[i] == '+') || (postfix[i] == '-') || (postfix[i] == '*') || (postfix[i] == '/') || (postfix[i] == '^'))
		{
			first = StD.Pop();
			second = StD.Pop();
			switch (postfix[i])
			{
			case '+':res = first + second; break;
			case '-':res = second - first; break;
			case '*':res = first * second;  break;
			case '/':res = second / first; break;
			case '^':res = pow(second, first); break;
			}
			StD.Push(res);
		}
		
		else if ((postfix[i] == 't') || (postfix[i] == 'g') || (postfix[i] == 's') || (postfix[i] == 'c') || (postfix[i] == 'l'))
		{
			char *tmp;
			int k = i;
			first = StD.Pop();
			switch (postfix[k])
			{
			case 'l':res = log(first); break;
			case 's':res = sin(first); break;
			case 'c':res = cos(first);  break;
			case 'g':res = 1/(tan(first)); break;
			case 't':res = tan(first); break;
			}
			StD.Push(res);
		}
		else if (((postfix[i] > '0') && (postfix[i]) <= '9') || (postfix[i] == '.')||( postfix[i] == '_' ))
		{
			char *tmp;
			if(postfix[i] == '_')
			{
				i++;
				res = - strtod(&postfix[i+1], &tmp);
			}
			else res = strtod(&postfix[i], &tmp);
			StD.Push(res);
			int g = tmp - &postfix[i];
			i += g - 1;
		}
	}
		return StD.Pop();
}

void TCalculator::SetInfix(string s)
{
	infix = s;
}

void TCalculator::GetPostfix()
{
	cout << postfix;
}


