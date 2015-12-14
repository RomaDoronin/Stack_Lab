#pragma once
template <class T>
class TStack
{
	int MaxSize;
	int Index;
	T *mas;
public:

	//�����������
	TStack(int _MaxSize = 10) 
	{
	   if (_MaxSize <= 0) throw _MaxSize;
	   MaxSize = _MaxSize;
	   Index = -1;
	   mas = new T[MaxSize];
    }

	//����������
	~TStack()
    {
	    delete[] mas;
    }

	//����������� �����������
	TStack(const TStack& S)
    {
	    MaxSize = S.MaxSize;
	    Index = S.Index;
	    mas = new T[MaxSize];
	    for(int i = 0; i<Index; i++)
		    mas[i] = s.mas[i];
    }

	//���������� �������� "="
    TStack& TStack::operator=(const TStack& S)
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

	int TStack::RetInt() {return Index;}
	//������� ������������ ����
    bool TStack::IsEmpty() {return Index = -1;}

	//������� �������� ���� ������������� �������
    bool TStack::IsFull() {return(Index == MaxSize-1);}

	//������� ������������ �������� �������� �� ������� �����
    T TStack::TTop()
    {
	    if (Index=-1) throw Index;
	    return mas[Index];
    }

	//������� ������������� ������� �� �����
    T TStack::TPop()
    {
//	    if Index = -1 throw Index;
	    T tmp = mas[Index];
	    Index--;
	    return tmp;
    }

	//������� �������� ������� � ����
    void TStack::TPush(const T& n)
    {
	    if (Index == MaxSize-1) throw Index;
	    Index++;
	    mas[Index]=n;
    }
};

