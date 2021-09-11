#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int a[16];
int b[16];
int check[16];
int N , M;
int cnt = 0;
void DFS(int x)
{
	if (x == N + 1)
	{
		for (int i = 1; i < x-1; i++)
		{
			printf("%d ", b[i]);
		}
		printf("\n");
		cnt++;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == 0)
			{
				b[x] = a[i];//여기가 매우중요 
				check[i] = 1;
				DFS(x + 1);
				check[i] = 0;
			}
		}
	}
}

int main(void)
{
	int now = 1;
	int x, y;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	DFS(1);
	printf("%d", cnt);
}
