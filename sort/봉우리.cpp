#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int main(void)
{
	int N, M;
	int cnt = 0;
	int a[52][52] = { 0 };
	scanf("%d", &N);
	int k = 0;
	//vector<int> a(N+1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (k = 0; k < 4; k++)
			{
				if (a[i][j] <= a[i + dx[k]][j + dy[k]] && a[i + dx[k]][j + dy[k]] != 0)
				{
					break;
				}
			}
			if (k == 4)
			{
				cnt++;
			}
		}
	}
	printf("%d", cnt);
}
