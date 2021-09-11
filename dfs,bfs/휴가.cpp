#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N , M;
int cnt = 0;
int mm = -9999;

vector <pair<int,int>> a;
void DFS(int x,int sum)
{
	if (x > N)return;
	if (x == N)
	{
		if (mm < sum)
		{
			mm = sum;
		}
	}
	else
	{
		DFS(a[x].first + x,sum+a[x].second);
		DFS(x + 1,sum);
	}
}

int main(void)
{
	int now = 1;
	int x, y;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &x, &y);
		a.push_back(make_pair(x, y));
	}

	DFS(0,0);

	printf("%d", mm);
}
