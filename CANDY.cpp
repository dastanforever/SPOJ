#include <vector>
#include <stdio.h>

using namespace std;

int main(void)
{
	int N,i,ele;
	vector < int > packet;
	long long int sum = 0,res = 0;
	scanf("%d",&N);
	while(N != -1)
	{
		for (i = 0; i < N; ++i)
		{
			scanf("%d",&ele);
			packet.push_back(ele);
			sum += ele;
		}
		if (sum % N != 0)
		{
			printf("-1\n");
		}
		else
		{
			int mean = sum / N;
			for (i = 0; i < packet.size(); ++i)
			{
				if (packet[i] < mean)
				{
					res += mean - packet[i];
				}
			}
			printf("%lld\n",res);
		}
		scanf("%d",&N);
	}
}