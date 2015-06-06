#include <cstdio>

using namespace std;

int main(void)
{
	long long int t,num;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&num);
		printf("%lld\n",((num)*(num+2)*(2*num + 1)/8 ));
	}
	return 0;
}