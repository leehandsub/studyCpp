#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N,M;
	int res,sub;
	int sum = 0;
	int max = 0;
	scanf("%d %d", &N,&M);


	for (int i = 0; i < N; i++)
	{
		scanf("%d",&res);
		if (res > M)
		{
			sum++;
		}
		if (res <= M)
		{
			sum = 0;
		}
		if (max < sum)
		{
			max = sum;
		}
		
	}
	printf("%d", max);


}
