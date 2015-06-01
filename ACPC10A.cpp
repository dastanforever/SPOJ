#include <iostream>
#include <stdio.h>

using namespace std;

int main(void)
{
	long long int a1,a2,a3,res;
	scanf("%lld %lld %lld", &a1,&a2,&a3);
	while(a1 != 0 || a2 != 0 || a3 != 0)
	{
		if (a2 - a1 == a3 - a2)
		{
			printf("AP %lld\n", a3 + (a3 - a2));
		}
		else
		{
			printf("GP %lld\n", (a3*a3)/a2);
		}
		scanf("%lld %lld %lld", &a1,&a2,&a3);
	}
	return 0;
}