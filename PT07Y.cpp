#include <cstdio>
#include <string.h>

using namespace std;

int parent[10005];

int findparent(int node)
{
	if(parent[node] == -1)
	{
		return node;
	}
	return parent[node] = findparent(parent[node]);
}

int main(void)
{
	int i,flag;
	int m,n,e1,e2,p1,p2;
	scanf("%d%d",&n,&m);
	if (m != n-1)
	{
		printf("NO\n");
		return 0;
	}
	memset(parent,-1,sizeof parent);
	flag = 0;
	for (i = 0; i < m; ++i)
	{
		scanf("%d%d",&e1,&e2);
		p1 = findparent(e1);
		p2 = findparent(e2);
		if (p1 == p2)
		{
			flag  = 1;
			break;
		}
		parent[p1] = p2;
	}
	if (flag == 1)
	{
		printf("NO\n");
	}
	else
		printf("YES\n");
	return 0;
}
