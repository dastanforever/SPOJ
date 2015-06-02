#include <stdio.h>
#include <map>
#include <algorithm>

using namespace std;

// Map's Key = byteland coin.
// Map's Value = Max value for it's exchange.

map < long long int, long long int > exchange;

long long int returnmax(long long int n)
{
	if (n < 1)
	{
		return n;
	}
	else
	{
		if (exchange.find(n) == exchange.end())
			exchange[n] = max(n,returnmax(n/2)+returnmax(n/3)+returnmax(n/4));
		return exchange[n];
	}
}

int main(void)
{
	long long int n;
	while(scanf("%lld",&n)!= EOF)
	{
		printf("%lld\n",returnmax(n));
	}
	return 0;
}