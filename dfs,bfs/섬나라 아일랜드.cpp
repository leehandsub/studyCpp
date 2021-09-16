#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N , M;
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int a[21][21];

queue<pair<int, int>> q;

int main(void)
{
	int now = 1;
	int x, y;
	int temp;
	int cnt = 0;
	scanf("%d", &N);

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
			if (a[i][j] == 1)
			{
				q.push(make_pair(i, j));
				a[i][j] = 0;
				while (!q.empty())
				{
					x = q.front().first;
					y = q.front().second;
					q.pop();
					for (int k = 0; k < 8; k++)
					{
						if (a[x + dx[k]][y + dy[k]]==1)
						{
							a[x + dx[k]][y + dy[k]] = 0;
							q.push(make_pair(x + dx[k], y + dy[k]));
						}
					}
				}
				cnt++;
			}
		
		}
	}
	printf("%d", cnt);

	
}
