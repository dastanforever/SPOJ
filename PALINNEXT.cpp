#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

string st;
vector < int > vec1,vec2;

void intovec();
int checkallnine();
void addinmiddle();
void makepalin();
void printfromvec(int );
int checkbig();

void intovec()
{
	int i;
	for (i = 0; i < st.size(); ++i)
	{
		vec1.push_back((int)st[i] - 48);
	}
}

// Returns 0 if both equal;
// Returns 1 if vec1 big;
// Returns 2 if vec2 big;

int checkbig(int n)
{
	int i;
	for (i = 0; i < vec1.size(); ++i)
	{
		
	}
}

int checkallnine()
{
	int flag = 1,i;
	for (i = 0; i < vec1.size(); ++i)
	{
		if (vec1[i] != 9)
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
			vec1[i] += carry + flag;
			if (vec1[i] > 9)
			{
				carry = vec1[i] % 10;
			}
			vec1[i] = vec1[i] - (carry*10);
			flag = 0;
		}
	}
	else
	{
		for (i = (int)(st.size()/2); i >= 0; --i)
		{
			vec1[i] += carry + flag;
			if (vec1[i] > 9)
			{
				carry = vec1[i] % 10;
			}
			vec1[i] = vec1[i] - (carry*10);
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
		
	}
	printf("\n");
}

int main(void)
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		vec1.clear();
		vec2.clear();
		cin>>st;
		intovec();
		makepalin();
	}
	return 0;
}