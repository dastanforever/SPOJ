#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string message;
int t,startpos1,startpos2,startpos3;

void printres(int ch, int num1, int num2)
{
	if (ch == 1)
	{
		for (i = 0; i < startpos3; ++i)
		{
			printf("%c", message[i]);
		}
		printf(" %d\n",num1+num2);
	}
	if (ch == 2)
	{
		printf("%d ",num2 - num1);
		for (i = startpos2; i < message.size(); ++i)
		{
			printf("%c",message[i]);
		}
		printf("\n");
	}
	if (ch == 3)
	{
		for (int i = 0; i < startpos2; ++i)
		{
			/* code */
		}
	}
}


int main(void)
{
	int i = 0,num1 = 0, num2 = 0;
	scanf("%d",&t);
	while(t--)
	{
		cin>>message;
		startpos1 = message.find("machula");
		startpos2 = message.find("+");
		startpos3 = message.find("=");
		i = 0;
		num1 = 0;
		num2 = 0;
		if (startpos3 < startpos1)
		{
			// after '='
			// Add the nums.
			// print upto '='.
			// then result.


			while(message[i] != '=' && i < message.size())
			{
				while(message[i] != ' ')
				{
					num1 = (num1*10) + ((int)message[i] - 48);
					i++;
				}
				i += 3;
				while(message[i] != ' ')
				{
					num2 = (num2*10) + ((int)message[i] - 48);
					i++;
				}
				printres(1,num1,num2);
				i++;
			}

		}
		else
		{
			if (startpos1 < startpos2)
			{
				// Before '+'
				// Subtract the after '+'
				// from after '='.
				// print from +.
				i = startpos2 + 2;
				while(message[i] != ' ' && i < message.size())
				{
					num1 = (num1*10) + ((int)message[i] - 48);
					i++;
				}
				i += 3;
				while(message[i] != ' ' && i < message.size())
				{
					num2 = (num2*10) + ((int)message[i] - 48);
					i++;
				}
				printres(2,num1,num2);
			}
			else
			{
				// Between + and '='
				// print upto '+'
				// print result.
				// print after =.
				i = 0;
				while(message[i] != ' ' && i < startpos2)
				{
					num1 = (num1 * 10) + ((int)message[i]-48);
					i++;
				}
				i = startpos3+2;
				while(i < message.size())
				{
					num2 = (num2 * 10) + ((int)message[i]-48);
					i++;
				}
				printres(3,num1,num2);
			}
		}
	}
	return 0;
}