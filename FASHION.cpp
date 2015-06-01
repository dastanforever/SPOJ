#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void)
{
	int t,n,ele,res,i;
	vector < int > men, women;
	scanf("%d",&t);
	while(t--)
	{
		res = 0;
		men.clear();
		women.clear();
		n = 0;
		scanf("%d",&n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&ele);
			men.push_back(ele);
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&ele);
			women.push_back(ele);
		}
		sort(men.begin(),men.begin()+n);
		sort(women.begin(),women.begin()+n);
		for (i = 0; i < men.size(); ++i)
		{
			res += men[i]*women[i];
		}
		printf("%d\n",res);
	}
	return 0;
}