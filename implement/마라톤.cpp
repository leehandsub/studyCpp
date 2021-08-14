#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N,M;
	int pe[10001];
	int gr[10001];
	int sum = 1;
	int max = -999999;
	int now;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &pe[i]);
		gr[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (pe[i] <= pe[j])
			{
				gr[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", gr[i]);
	}

}
