#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

vector < int > primeArray,rangeAns;


void makemyprimes()
{
	int i,j;
	
	for (i = 2; i < primeArray.size(); ++i)
	{
		if (primeArray[i] == 1)
		for (j = i * i; j < primeArray.size(); j += i)
		{
			primeArray[j] = 0;
		}
	}
}

void makeprimes(long long int l,long long int u)
{
	int i,j;
	for (i = 0; i < 100000; ++i)
	{
		rangeAns.push_back(1);
	}
	if (l == 1)
	{
		rangeAns[0] = 0;
	}
	long long int endcheck = (int)(sqrt(u));
	for (i = 2; i <= endcheck; ++i)
	{
		if (primeArray[i] == 1)
		{
			long long int startpos = (l + (i - (l % i)));
			if (startpos == i)
			{
				startpos += i;
			}
			else if (l % i == 0 && l != 2)
			{
				startpos = l;
			}
			for (j = startpos; j <= u; j += i)
			{
				rangeAns[j - l] = 0;
			}
		}
	}

	// print the primes.
	for (i = l; i <= u; ++i)
	{
		if (rangeAns[i - l] == 1)
		{
		//cout<<i<<endl;
		printf("%d\n",i);
		}
	}
	rangeAns.clear();
}


int main(void)
{
	long long int l,u;
	int t,i;
	//cin>>t;
	scanf("%d",&t);
	for (i = 0; i < 100000; ++i)
	{
		primeArray.push_back(1);
	}
	makemyprimes();
	while(t--)
	{
		//cin>>l>>u;
		scanf("%lld %lld",&l,&u);
		makeprimes(l,u);
	}
	return 0;
}