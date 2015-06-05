#include <cstdio>
#include <iostream>
#include <limits>

using namespace std;

string message;

int main(void)
{
	int t,a,b,c,i;
	scanf("%d",&t);
	cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
	while(t--)
	{
		getline(cin,message);
		while(message.length() < 3)
		getline(cin,message);
		int it = 0;
		for (i = 0;message[i] !='m' && i < message.length(); ++i)
		{
			if (message[i] == '+' || message[i] == '=')
			{
				it++;
			}
		}
		if (it == 0)
		{
			sscanf(message.c_str(),"%*s + %d = %d", &b,&c);
			a = c - b;
		}
		else if (it == 1)
		{
			sscanf(message.c_str(),"%d + %*s = %d",&a,&c);
			b = c - a;
		}
		else
		{
			sscanf(message.c_str(),"%d + %d = %*s",&a,&b);
			c = a + b;
		}
		printf("%d + %d = %d\n",a,b,c);
	}
	return 0;
}