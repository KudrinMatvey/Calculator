#include"C:\Users\Матвей\Desktop\Tstack\TStack.h"
#include "C:\Users\Матвей\Documents\Visual Studio 2015\Projects\TStack new\gtest\gtest.h"

TEST(TStack, can_create_stack)
{
	ASSERT_NO_THROW(TStack<double> a);
}
TEST(TStack, can_check_empty_stack)
{
	TStack<double> a;
	EXPECT_TRUE(a.IsEmpty());
}
TEST(TStack, cannot_pop_from_empty_stack)
{
	TStack<int> a(2);	
	EXPECT_ANY_THROW(a.Pop());
}
TEST(TStack, can_push_and_see_top_element)
{
	TStack<double> a;
	a.Push(4);
	EXPECT_EQ(4,a.Top());
}
TEST(TStack, can_pop_element)
{
	TStack<double> a;
	a.Push(4);
	a.Pop();
	EXPECT_TRUE(a.IsEmpty());
}
TEST(TStack, can_check_full)
{
	TStack<int> a(2);
	a.Push(1);
	a.Push(2);
	EXPECT_TRUE(a.IsFull());
}
TEST(TStack,cannot_push_to_full_stack)
{
	TStack<int> a(2);
	a.Push(1);
	a.Push(2);
	EXPECT_ANY_THROW(a.Push(3));
}
TEST(TStack, can_copy_stack)
{
	TStack <double> a;
	a.Push(17);
	ASSERT_NO_THROW(TStack<double> b(a));
}
TEST(TStack, can_clear_stack)
{
	TStack<int> a(2);
	a.Push(1);
	a.Push(2);
	a.Clr();
	EXPECT_TRUE(a.IsEmpty());
}