#include <cstdio>
#include <math.h>

using namespace std;

int main(void)
{
	int t;
	long long int num,row,termstart,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&num);
		row = ceil(((sqrt(1 + 8 * num) - 1) / 2));
		// Sum upto row - 1.
		termstart = ((row - 1)*(row) / 2) + 1;
		// StartCounting.
		if (row%2 == 0)	i = 1;
		else i = row;
		while(termstart < num)
		{
			termstart++;
			if (row%2 == 0) i++;
			else i--;
		}
		printf("TERM %lld IS %lld/%lld\n",num,i,row-i+1);
	}

	return 0;
}