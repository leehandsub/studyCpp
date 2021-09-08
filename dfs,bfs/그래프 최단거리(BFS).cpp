#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dis[30];
int check[30];
vector <int> a[30];
queue<int> q;
int main(void)
{
	int N, M;
	int b, c;
	int x;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &b, &c);
		a[b].push_back(c);
	}
	q.push(1);
	check[1] = 1;
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++)
		{
			if (check[a[x][i]] == 0)
			{
				check[a[x][i]] = 1;
				q.push(a[x][i]);//중요
				dis[a[x][i]] = dis[x] + 1;//중요
			}
		}
	}
	for (int i = 2; i <= N; i++)
	{
		printf("%d : %d\n", i, dis[i]);
	}
}
