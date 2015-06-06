#include <cstdio>
#include <math.h>

using namespace std;

int main(void)
{
	float g,b;
	scanf("%f%f",&g,&b);
	while(g >=  0 && b >= 0)
	{
		if (g <= b)
			printf("%d\n",(int)ceil(b/(g+1)));
		else
			printf("%d\n",(int)ceil(g/(b+1)));
		scanf("%f%f",&g,&b);
	}
	return 0;
}