#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[1001];

int Find(int v)
{
	if (v == a[v])return v;
	else return Find(a[v]);//이건 매우 비효율... 
	//else return a[v]=Find(a[v]));조금이라도 효율적으로 
}

void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	if (x != y)a[x] = y;
}

int main(void)
{
	int now = 1;
	int N, M;
	int x, y;

	scanf("%d %d", &N, &M);

	for (int i = 0; i <= N; i++)
	{
		a[i] = i;
	}
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &x, &y);
		Union(x, y);
	}
	scanf("%d %d", &x, &y);
	x = Find(x);
	y = Find(y);
	if (x == y)printf("YES");
	else printf("NO");
}
//disjoint-set :union&find
//트리형태로 만듬
