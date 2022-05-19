#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[101][101];
int visit[101];
int num[101];
int answer[101];

int main(void)
{
	int n, m;
	int x, y;
	queue<int> q;
	int min = 999999999;
	int mini = -1;
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
		visit[i] = 1;
		while (!q.empty())
		{
			x = q.front();
			q.pop();
			for (int j = 1; j <= n; j++)
			{
				if (arr[x][j] == 1 && visit[j] == 0)
				{
					visit[j] = 1;
					q.push(j);
					num[j] = num[x] + 1;
				}
			}
		}//bfs³¡

		for (int j = 1; j <= n; j++)
		{
			answer[i] += num[j];
			num[j] = 0;
			visit[j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (min > answer[i])
		{
			min = answer[i];
			mini = i;
		}
	}
	printf("%d", mini);

}