#include <iostream>
#include <vector>

using namespace std;

vector < long long int > arr;

int main(void)
{
	long long int t,a,res,i;
	cin>>t;
	a = 1;
	while(1)
	{
		a *= 5;
		arr.push_back(a);
		if (a > 1000000000)
		{
			break;
		}
	}
	while(t--)
	{
		res = 0;
		cin>>a;
		i = 0;
		while((long long int)(a/arr[i]) > 0)
		{
			res += (long long int)a/arr[i];
			i++;
		}
		cout<<res<<endl;
	}
	return 0;
}