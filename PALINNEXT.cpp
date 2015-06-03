#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string st;
vector < int > vec;

void intovec();
int checkallnine();
void addinmiddle();
void makepalin();
void printfromvec(int );

void intovec()
{
	int i;
	for (i = 0; i < st.size(); ++i)
	{
		vec.push_back((int)st[i] - 48);
	}
}

int checkallnine()
{
	int flag = 1,i;
	for (i = 0; i < vec.size(); ++i)
	{
		if (vec[i] != 9)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void addinmiddle()
{
	int i,flag = 1;
	int carry = 0;
	if (st.size()%2 == 0)
	{
		for (i = st.size()/2 - 1; i >= 0; --i)
		{
			vec[i] += carry + flag;
			if (vec[i] > 9)
			{
				carry = vec[i] % 10;
			}
			vec[i] = vec[i] - (carry*10);
			flag = 0;
		}
	}
	else
	{
		for (i = (int)(st.size()/2); i >= 0; --i)
		{
			vec[i] += carry + flag;
			if (vec[i] > 9)
			{
				carry = vec[i] % 10;
			}
			vec[i] = vec[i] - (carry*10);
			flag = 0;
		}
	}
}

void makepalin()
{
	int i,j;
	if (st.size() == 1)
	{
		printfromvec(0);
		return;
	}
	if(checkallnine())
	{
		printfromvec(1);
		return;
	}
	i = ((int)st.size()/2) - 1;
	if (st.size() % 2 == 0)
		j = st.size()/2;
	else
		j = ((int)st.size()/2) + 1;
	while(i >= 0 && j < st.size())
	{
		if (vec[i] != vec[j])
		{
			break;
		}
		i--;j++;
	}
	if ((i > -1 && vec[i] < vec[j]) || i == -1)
	{
		addinmiddle();
	}
	printfromvec(2);
	printfromvec(3);
}

void printfromvec(int flag)
{
	int i;
	if (flag == 0) // single digit.
	{
		printf("11");
	}
	if (flag == 1)	// all 9's
	{
		printf("1");
		for (i = 1; i < st.size(); ++i)
		{
			printf("0");
		}
		printf("1");
	}
	if (flag == 2)
	{
		if(st.size()%2 == 0)
		{
			for (i = 0; i <= st.size()/2 - 1; ++i)
			{
				printf("%c",(char)(vec[i] + 48));
			}
		}
		else
		{
			for (i = 0; i <= (int)st.size()/2; ++i)
			{
				printf("%c",(char)(vec[i] + 48));
			}
		}
		return;
	}
	if (flag == 3)
	{
		if (st.size()%2 == 0)
		{
			for (i = st.size()/2-1; i >= 0; --i)
			{
				printf("%c",(char)(vec[i] + 48));
			}
		}
		else
		{
			for (i = ((int)st.size()/2) - 1; i >= 0; --i)
			{
				printf("%c",(char)(vec[i] + 48));
			}
		}
	}
	printf("\n");
}

int main(void)
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		vec.clear();
		cin>>st;
		intovec();
		makepalin();
	}
	return 0;
}