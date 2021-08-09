#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int sum = 0;
	
	char N[100];
	scanf("%s", &N);


	for (int i = 0; N[i]!='\0'; i++)
	{
		if (N[i] == '(')
		{
			sum++;
		}
		if (N[i] == ')')
		{
			sum--;
		}
		if (sum < 0)
		{
			break;
		}

	}
	if (sum == 0)printf("yes");
	else printf("NO");


}
