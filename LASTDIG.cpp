#include <stdio.h>

int main(void)
{
	long long int b,e,res = 1;
	int i,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld %lld",&b,&e);

		res = 1;
		
		while(e)
		{
			if (e % 2 == 1)
			{
				res = (res*b)%10;
			}
			b = (b*b)%10;
			e >>= 1;
		}

		printf("%lld\n",res);
	}
}