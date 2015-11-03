#include "StdAfx.h"
#include "TStack.h"


TStack::TStack& operator=(const TStack& S)
{
	if (MaxSize != S.MaxSize)
	{
		delete[] mas;
		MaxSize = S.MaxSize;
		mas = new T[MaxSize];
	}
	Index = S.Index;
	for (int i=0; i<=Index; i++)
		mas[i]=S.mas[i];
	return *this
}

bool TStack::IsEmpty() {return Index = -1;}

bool TStack::IsFull() {return(Index == MaxSize-1);}

int TStack::TTop()
{
	if (Index=-1) throw Index;
	return mas[index];
}

T TStack::TPop()
{
	if Index = -1 throw Index;
	T tmp = mas[Index];
	Index--;
	return tmp;
}

void TStack::TPash(const T& n)
{
	if (Index == MaxSize-1) throw Index;
	Index++;
	mas[Index]=n;
}

/*
int Check (char*str)
{
	TStack <char> C(10);
	int i=0;
	while (str[i] != '\0')
		if (isr[i] = '(')
			S.Push('(');
	if (str[i]=')')
*/