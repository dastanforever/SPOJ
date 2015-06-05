#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector < int > stamp;

int main(void)
{
	int t,need,totfrnds,i,acc,flag,ele;
	scanf("%d",&t);
	int t2 = t;
	while(t--)
	{
		scanf("%d %d",&need,&totfrnds);
		for (i = 0; i < totfrnds; ++i)
		{
			scanf("%d",&ele);
			stamp.push_back(ele);
		}
		// Reverse sort the vector.
		std::sort(stamp.begin(), stamp.end(), std::greater<int>());
		i = 0;
		acc = 0;
		flag = 1;
		printf("Scenario #%d:\n",t2 - t);
		while(acc < need)
		{
			if (stamp.size() == 0)
			{
				flag = 0;
				printf("impossible\n");
				break;
			}
			acc += stamp[0];
			stamp.erase(stamp.begin());
			i++;
		}
		if (flag == 1) printf("%d\n", i);
		stamp.clear();
	}
	return 0;
}