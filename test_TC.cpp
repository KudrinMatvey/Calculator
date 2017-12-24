#include "C:\Users\Матвей\Desktop\Tstack\TCalculator.cpp"
#include "C:\Users\Матвей\Documents\Visual Studio 2015\Projects\TStack new\gtest\gtest.h"

TEST(TCalculator, can_set_infix)
{
	TCalculator tc;
	string s = "3+2";
	ASSERT_NO_FATAL_FAILURE(tc.SetInfix(s));
}

TEST(TCalculator, can_check_incorrect_expression)
{
	TCalculator tc;
	string s = "2+*3";
	tc.SetInfix(s);
	EXPECT_EQ(0, tc.IsCorrect());
}

TEST(TCalculator, can_check_correct_expression)
{
	TCalculator tc;
	string s = "2+3";
	tc.SetInfix(s);
	EXPECT_EQ(1, tc.IsCorrect());
}

TEST(TCalculator, can_substract_two_numbers)
{
	TCalculator tc;
	string s = "2-3";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(-1, res);
}

TEST(TCalculator, can_sum_two_numbers)
{
	TCalculator tc;
	string s = "2+3";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(5, res);
}

TEST(TCalculator, can_divide_two_numbers)
{
	TCalculator tc;
	string s = "6/3";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(2, res);
}

TEST(TCalculator, can_multiply_two_numbers)
{
	TCalculator tc;
	string s = "2*3";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(6, res);
}

TEST(TCalculator, can_calculate_expressions_with_brackets)
{
	TCalculator tc;
	string s = "3*(2+3)";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(15, res);
}

TEST(TCalculator, can_calculate_negative_numbers)
{
	TCalculator tc;
	string s = "-2*(-3)";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(6, res);
}

TEST(TCalculator, can_calculate_sin)
{
	TCalculator tc;
	string s = "sin0";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(0, res);
}

TEST(TCalculator, can_calculate_cos)
{
	TCalculator tc;
	string s = "cos0";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(1, res);
}

TEST(TCalculator, can_calculate_tan)
{
	TCalculator tc;
	string s = "tan0";
	tc.SetInfix(s);
	tc.topostfix();
	double res = tc.Calc();
	EXPECT_EQ(0, res);
}
