#pragma once
#include<iostream>

template <class T>

class TStack
{
	int MaxSize;
	int Size;
	T * Mas;

public:
	TStack(int _MaxSize = 100)
	{
		MaxSize = _MaxSize;
		Size = 0;
		Mas = new T[MaxSize];
	}
	TStack(const TStack &ts)
	{
		MaxSize = ts.MaxSize;
		Size = ts.Size;
		Mas = new T[MaxSize];
		for (int i = 0; i < Size; i++) Mas[i] = ts.Mas[i];
	}
	~TStack() { delete[] Mas; }
	bool IsEmpty() const
	{
		if (Size == 0) return true;
		else return false;
	}
	bool IsFull() const
	{
		if (Size == MaxSize) return true;
		else return false;
	}
	void Clr()
	{
		Size = 0;
	}
	void Push(T a)
	{
		if (IsFull()) throw a;
		else {
			Mas[Size] = a;
			Size++;
		}
	}
	T Top() const
	{
		if(!IsEmpty())return Mas[Size - 1];
		else throw 1;
	}
	T Pop()
	{
		if (!IsEmpty())
		{
			Size--;
			return Mas[Size];
		}
		else throw 1;
	}
};
