#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dis[3] = { -1,1,5 };
int check[20000];
queue<int> q;
int main(void)
{
	int N, M;
	int x;
	int cnt=0;
	int now;
	scanf("%d %d", &N, &M);
	check[N] = 1;
	q.push(N);

	while (!q.empty())
	{
		x = q.front();
		q.pop();

		for (int i = 0; i < 3; i++)
		{
			now = x + dis[i];
			if (now <= 0)
			{
				continue;
			}
			if (now == M)
			{
				printf("%d", check[x]);
				return 0;
			}
			if (check[now] == 0)
			{
				check[now] = check[x]+1;
				q.push(now);
			}
		}

	}
	
}
