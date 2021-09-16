#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N , M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int a[10][10];
int b[10][10];
queue<pair<int, int>> q;

int main(void)
{
	int now = 1;
	int x, y;
	int temp;
	int cnt = 0;

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			a[i][j] = 1;
		}
	}

	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	q.push(make_pair(1, 1));
	a[1][1] = 1;
	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (a[x + dx[i]][y + dy[i]] == 0)
			{
				a[x + dx[i]][y + dy[i]] = 1;
				q.push(make_pair(x + dx[i], y + dy[i]));
				b[x + dx[i]][y + dy[i]] = b[x][y]+ 1;
			}
		}
	}
	printf("%d", b[7][7]);
}
