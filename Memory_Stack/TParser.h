#pragma once

#define MaxLen 201

#include "TStack.h"
#include "string.h"


class TParser
{
	char inf[MaxLen];
	char post[MaxLen];
	TStack <double> st_d;
	TStack <char> st_c;

public:
	//Конструктор
	TParser(char* s=NULL):st_d(100),st_c(100)
	{
		if (s==NULL) inf[0] = '\0';
		else strcpy(inf,s);
		st_c.TPush(')');
	}

	//Деструктор
	~TParser();

	int Priority(char sign)
	{
		int Pr;
		switch(sign)
		{
		case '(': Pr=0; break;
		case ')': Pr=0; break;
		case '+': Pr=1; break;
		case '-': Pr=1; break;
		case '*': Pr=2; break;
		case '/': Pr=2; break;
		case '^': Pr=3; break;
		default: Pr=-1;
		}
		return(Pr);
	}


	/*bool IsOpen(char ch)
	{
		if (ch==*/

	void inftopost()
	{
		int i=0,j=0;
		while(inf[i] != '\0')
		{
			if ((inf[i] != '+') || (inf[i] != '-') || (inf[i] != '*') || (inf[i] != '/') || (inf[i] != '^') || (inf[i] != '(') || (inf[i] != ')'))
			{ post[j] = inf[i]; j++; }
			else
			{
				while(st_c.RetInt() != -1)
				{
				    if ( Priority(inf[i]) > Priority(st_c.TTop()) )
						{st_c.TPush(inf[i]); break;}
				    else
				        {
 					        post[j] = st_c.TTop();
							j++;
					        st_c.TPop();
				        }
				}
			}
			i++;
		}
		while (st_c.TTop() == ')')
		{
			post[j] = st_c.TTop();
			j++;
			st_c.TPop();
		}
	}

};

