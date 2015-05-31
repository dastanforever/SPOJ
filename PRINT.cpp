#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 0 means prime.
// 1 means not prime.

vector < int > primes;
vector < int > segment;

void addtomainsieve()
{
	int i;
	for (i = 0; i < segment.size(); ++i)
	{
		primes.push_back(segment[i]);
	}
}

// number  = 2 * index + 3

void makesieveprime()
{
	int i, j, num,k;
	int iter = 2048,offset;
	for (k = 0; k < iter; ++k)
	{
		for (i = 0; i < primes.size(); ++i)
		{
			startnum = ((k * 1000000) - (k * 1000000) % 3);
			if (startnum % 2 == 0)
				startnum += i;
			offset = (startnum - 3) / 2;
			num = 2 * i + 3;
			if (segment[i] == 0)
			{
				for (j = i + num; j < segment.size(); j += num)
				if ((2 * j + 3)+(k * 1000000)) % num == 0)
					segment[j] = 1;
			}
		}
		addtomainsieve();
	}
}

void printall(long long int l, long long int u)
{
	int indexstart = (l - 3)/2;
	int indexend = (u - 3)/2;
	int i;
	for (i = indexstart; i <= indexend; ++i)
		if (primes[i] == 0)
			cout<<2*i+3<<endl;
}

void makesegment()
{
	int i;
	for (i = 0; i < 2147483647; ++i)
		segment.push_back(0);
}

int main(void)
{
	int t;
	long long int l,u;
	cin>>t;
	makesegment();
	makesieveprime();
	cout<<"9 : "<<segment[3]<<endl;
	cout<<"13 : "<<segment[5]<<endl;
	cout<<"33 : "<<segment[15]<<endl;
	while(t--)
	{
		cin>>l>>u;
		if (l == 2)
		{
			cout<<"2"<<endl;
		}
		printall(l,u);
	}
}