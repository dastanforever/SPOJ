#include <stdio.h>
#include <vector>

using namespace std;

vector < long long int > divsum;

void makediv()
{
	int i,j;
	for (i = 0; i <= 500000; ++i)
	{
		divsum.push_back(0);
	}
	for (i = 1; i <= 500000; ++i)
	{
		for (j = 2 * i; j <= 500000; j+=i)
		{
			divsum[j] += i;
		}
	}
}

int main(void)
{
	int t,num;
	scanf("%d",&t);
	makediv();
	while(t--)
	{
		scanf("%d",&num);
		printf("%lld\n", divsum[num]);
	}
	return 0;
}