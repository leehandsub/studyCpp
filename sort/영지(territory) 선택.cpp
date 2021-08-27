#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[701][701];
int b[701][701];
int main(void)
{
	int N, M;
	int cnt = 0;
	int c, d;
	int max = -99999;
	int num=0;
	int sum =0;
	int temp = 0;

	scanf("%d %d",&N ,&M);

	//vector<int> a(N+1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &a[i][j]);
			if (j==0&&i==0)
			{
				b[i][j] = a[i][j];
			}
			else if(i==0)
			{
				b[i][j] = a[i][j] + b[i][j-1];
			}
			else if (j == 0)
			{
				b[i][j] = a[i][j] + b[i-1][j];
			}
			else
			{
				b[i][j] = a[i][j] + b[i - 1][j] + b[i][j - 1]-b[i-1][j-1];
			}
		}
	}
 	scanf("%d %d", &c, &d);
	for (int i = c-1; i < N; i++)
	{
		for (int j = d-1; j < M; j++)
		{
			
			if (i == c - 1 && j == d - 1)
			{
				temp = b[i][j];
			}
			else if (i == c - 1)
				temp = b[i][j] - b[i][j - d];
			else if (j == d - 1)
				temp = b[i][j] - b[i - c][j];
			else
				temp = b[i][j] - b[i - c][j] - b[i][j - d]+b[i-c][j-d];
			if (temp > max)
			{
				max = temp;
			}
		}
	}
	

	printf("%d", max);
}
