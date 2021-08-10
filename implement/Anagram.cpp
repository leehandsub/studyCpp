#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	char sub[101];
	int cnt[60] = { 0 };
	scanf("%s", sub);
	for(int i=0;sub[i]!='\0'; i++)
	{
		cnt[sub[i] - 64]++;
	}
	scanf("%s", sub);
	for (int i = 0; sub[i] != '\0'; i++)
	{
		cnt[sub[i] - 64]--;
	}
	for (int i = 0; i < 50; i++)
	{
		if (cnt[i] !=0 )
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	

}
