#include <stdio.h>

using namespace std;

int main(void)
{
	float c,ele,i;
	while(scanf("%f",&c) != 0.00)
	{
		if (c == 0.00)
		{
			return 0;
		}
		ele = 0.5;
		i = 1;
		while(ele < c)
		{
			i++;
			ele += (1/(i+1));
		}
		printf("%d card(s)\n", (int)i);
	}
	return 0;
}