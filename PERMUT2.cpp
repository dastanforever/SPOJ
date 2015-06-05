#include <cstdio>
#include <string.h>

using namespace std;

int arr[100005];

int main(void)
{
	int l,flag,i;
	scanf("%d",&l);
	while(l != 0)
	{
		memset(arr,0,sizeof arr);
		flag = 0;
		for (i = 1; i <= l; ++i)
		{
			scanf("%d",&arr[i]);
		}
		for (i = 1; i <= l; ++i)
		{
			if (arr[i] != i && i != arr[arr[i]])
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
		scanf("%d",&l);
	}

	return 0;
}