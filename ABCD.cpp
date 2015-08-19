#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int N,i;

int main(void)
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	scanf("%d",&N);
	string str,res(100005,'x');
	//fgets(str, 00, stdin);
	cin>>str;
	
	for(i = 0; i < 2*N; i += 2)
		{
			char l,t,r,resl;
			
			l = (i == 0) ? 'A': res[i-1];
			t = str[i];
			r = str[i+1];
			// for arr[1][i].
			for(resl = 'A';;resl++) if(resl != l && resl != t && resl != r ) { res[i] = resl; break; }
			
			// for arr[1[i+1].
			l = res[i];
			t = str[i+1];
			r = str[i];
			for(resl = 'A';;resl++) if(resl != l && resl != t && resl != r ) { res[i+1] = resl; break; }
			printf("%c%c", res[i],res[i+1]); 
		}
	return 0;
}