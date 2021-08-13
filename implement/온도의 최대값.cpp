#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N,M;
	int sum1 = 0;
	int sum2 = 0;
	int pe1[100001];
	//int pe2[10];
	int sum = 0;
	int max = -999999;
	scanf("%d %d", &N,&M);


	for (int i = 0; i < N; i++)
	{
		scanf("%d",&pe1[i]);
	}
	for (int i = 0; i < M - 1; i++)
	{
		sum += pe1[i];
	}

	for (int i = M-1; i < N; i++)
	{
		sum += pe1[i];
		if (max < sum)
		{
			max = sum;
		}
		sum -= pe1[i - (M - 1)];
		
	}
	printf("%d", max);
}


