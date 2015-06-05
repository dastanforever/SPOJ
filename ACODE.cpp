#include <cstdio>
#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>

using namespace std;

string num;

long int numres;
int dp[5005];

int getnum(int index)
{
	if (num[index] == '0') return 0;
	if (dp[index]) return dp[index];
	if (index >= num.length() - 1) return 1;
	else
	{
		if (((int)num[index] - 48) * 10 + ((int)num[index + 1] - 48) <= 26)
			return dp[index] = getnum(index+2) + getnum(index + 1);
		else
			return dp[index] = getnum(index+1);
	}
}

int main(void)
{
	cin>>num;
	while(num[0] != '0')
	{
		memset(dp,0,sizeof(dp));
		printf("%d\n", getnum(0));
		cin>>num;
	}
	return 0;
}