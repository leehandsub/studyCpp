#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N,M;
	int sum1 = 0;
	int sum2 = 0;
	int pe1[10];
	int flag = 0;
	int pe2[10];
	//int sum = 0;
//	int max = 0;
	//scanf("%d", &N);


	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&pe1[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &pe2[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		if (pe1[i] > pe2[i])
		{
			sum1 += 3;
			flag = 1;
		}
		else if (pe1[i] < pe2[i])
		{
			sum2 += 3;
			flag = 2;
		}
		else
		{
			sum1++;
			sum2++;
		}
	}
	printf("%d %d\n", sum1, sum2);
	if (sum1 == sum2)
	{
		if (flag == 1)
		{
			printf("A");
		}
		else if (flag == 2)
		{
			printf("B");
		}
		else
		{
			printf("D");
		}
	}
	else if (sum1 > sum2)
	{
		printf("A");
	}
	else if (sum2 < sum1)
	{
		printf("B");
	}


}
