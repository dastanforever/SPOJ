#include <stdio.h>

using namespace std;

int main(void)
{
	long long int ele,t,n,i,res=0;
	scanf("%lld",&t);
	while(t--)
	{
		res = 0;
		scanf("%lld",&n);
		for (i = 0; i < n; ++i)
		{
			scanf("%lld",&ele);
			res = ((res % n) + (ele % n)) % n;
		}
		if (res % n == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}