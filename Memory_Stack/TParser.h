#pragma once

#define MaxLen 201

#include "TStack.h"
#include <string.h>


class TParser
{
	char* inf[MaxLen];
	char* post[MaxLen];
	TStack <double> st_d;
	TStack <char> st_c;

public:
	//Конструктор
	TParser(char* s=NULL):st_d(100),st_c(100)
	{
		if (s==NULL) inf[0] = '\0';
		else strcpy(inf,s);
	}

	//Деструктор
	~TParser();

	int Priority(char ch)
	{
		int n;
		switch(ch)
		{
		case '(': n=0; break;
		case ')': n=0; break;
		case '+': n=1; break;
		case '-': n=1; break;
		case '*': n=2; break;
		case '/': n=2; break;
		case '^': n=3; break;
		default n=-1;
		}
		return(n);
	}


	/*bool IsOpen(char ch)
	{
		if (ch==*/

	void inftopost()
	{
		int i=0;
		while(inf[i] != '\0')
		{
			if ((inf[i] != "+") || (inf[i] != "-") || (inf[i] != "*") || (inf[i] != "/") || (inf[i] != "^"))
		    post[i] = inf[i];
			else
			{
				if ((Priority(inf[i]) > Priority(st_c.TTop)) && (st_c.RetInt() != -1))
				   st_c.TPush(inf[i]);
				else
				{
					post[i] = inf[i];
					st_c.TPop();
				}


            i++;
};

