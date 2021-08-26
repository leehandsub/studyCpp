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
	int a[9][9] = { 0 };
	//scanf("%d", &N);
	N = 9;
	//vector<int> a(N+1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sum += a[i][j];
		}
		ave = (sum / 9.0) + 0.5;//반올림..
		printf("%d " , ave);
		for (int j = 0; j < N; j++)
		{
			int temp = abs(a[i][j] - ave);
			if (temp < min)
			{
				min = temp;
				num = a[i][j];
			}
			else if (temp == min)
			{
				if (a[i][j] > num)
				{
					num = a[i][j];
				}
			}
		}
		printf("%d\n", num);
		min = 9999;
		sum = 0;
	}
}
