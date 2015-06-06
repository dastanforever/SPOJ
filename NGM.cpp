#include <iostream>
using namespace std;

int main() {
	
	// your code here
	long long int n;
	cin>>n;
	if (n%10 == 0)
	{
		cout<<2<<endl;
		return 0;
	}
	cout<<1<<endl;
	cout<<n%10<<endl;
	return 0;
}