#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	int cnt = 0;
	int min = 9999;
	int ave = 0;
	int num=0;
	int sum = 0;
	int a[11][11] = { 0 };
	scanf("%d", &N);

	//vector<int> a(N+1);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		for (int j = 0; j < N; j++)
		{
			a[j][i] = num;
			sum += num;
		}
	}
	for (int i = N-1; i >= 0; i--)
	{
		scanf("%d", &num);
		for (int j = 0; j < N; j++)
		{
			if (num < a[i][j])
			{
				sum -= a[i][j];
				a[i][j] = num;
				sum += a[i][j];
			}
		}
	}
	printf("%d", sum);
}
