#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N,M;
	int pe1[100001];
	//int pe2[10];
	int sum = 1;
	int max = -999999;
	int now;
	int pre=9999999;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{

		scanf("%d", &now);
		
		if (pre <= now)
		{
			sum++;
		}
		else
		{
			sum = 1;
		}
		if (max < sum)
		{
			max = sum;
		}
		
		pre = now;
	}
	
	printf("%d", max);
}
