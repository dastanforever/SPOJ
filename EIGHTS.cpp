#include <stdio.h>

int main(void)
{
	long long int k,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&k);
		printf("%lld\n", 192 + (250*(k - 1)));
	}
	return 0;
}