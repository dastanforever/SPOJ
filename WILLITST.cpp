#include <cstdio>

using namespace std;

int main(void)
{
	long long int num;
	scanf("%lld",&num);
	if (((num)&(num-1)) == 0)
		printf("TAK\n");
	else
		printf("NIE\n");
	return 0;
}
