#include <stdio.h>

int main(void)
{
	int t,b,e,i,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&b,&e);
		res = 1;
	for (i = 0; i < e; ++i)
	{
		res = (res * b)%10;
	}
	printf("%d\n",res);
	}
}