#pragma once
#include <string>
#include <cmath>
#include <iostream>
#include "TStack.h"

using namespace std;

class TCalculator
{
	string infix;
	string postfix;
	int priority(char ch);
	TStack <char> StC;
	TStack <double> StD;
public:
	TCalculator();
	~TCalculator();
	void topostfix();
	bool IsCorrect();
	double Calc();
	void SetInfix(string s);
	void GetPostfix();
};


