#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int col,i,j,row;
	string st;
	scanf("%d",&col);
	while(col != 0)
	{
		cin>>st;
		row = st.size()/(2*col);
		
		printf("\n");
		scanf("%d",&col);
	}
	return 0;
}