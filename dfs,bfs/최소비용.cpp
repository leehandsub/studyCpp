#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check[30];
int mi = 99999999;
vector <pair<int,int>> a[30];
int cnt;
int N;
void dfs(int x,int sum)
{
	if (x == N)
	{
		if (sum < mi) 
		{
			mi = sum;
		}
	}
	else
	{
		for (int i = 0; i < a[x].size(); i++)
		{
			if (check[a[x][i].first]==0)
			{
				check[a[x][i].first] = 1;
				dfs(a[x][i].first,sum+a[x][i].second);
				check[a[x][i].first] = 0;
			}
		}
	}
}

int main(void)
{
	int M;
	int c, d,e;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &c, &d,&e);
		a[c].push_back(make_pair(d, e));
	}
	check[1] = 1;
	dfs(1,0);
	printf("%d", mi);
}
