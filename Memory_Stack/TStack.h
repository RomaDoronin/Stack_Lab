#pragma once
template <class T>
class TStack
{
	int MaxSize;
	int Index;
	T *mas;
public:
	TStack(int _MaxSize = 10)
	{
	   if (_MaxSize <= 0) throw _MaxSize;
	   MaxSize = _MaxSize;
	   Index = -1;
	   mas = new T[MaxSize];
    }

	~TStack()
    {
	    delete[] mas;
    }

	TStack(const TStack& S)
    {
	    MaxSize = S.MaxSize;
	    Index = S.Index;
	    mas = new T[MaxSize];
	    for(int i = 0; i<Index; i++)
		    mas[i] = s.mas[i];
    }

	TStack& operator=(const TStack& S);
	bool IsEmpty();
	bool IsFull() ;
	int TTop();
	T TPop();
	void TPash(const T& n);
};

