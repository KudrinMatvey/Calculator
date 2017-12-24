#include"stdafix.h"
#include"TStack.h"
#include"TCalculator.h"
int main()
{
	TCalculator ts;
	string s;
	cin >> s;
	ts.SetInfix(s);
	if (ts.IsCorrect())
	{
		
		ts.topostfix();
		ts.GetPostfix();
		double res = ts.Calc();
		cout << endl << res;
	}
	else cout << "\n cannot calculate";
	return 0;
}