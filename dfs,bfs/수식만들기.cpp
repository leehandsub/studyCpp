#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N , M;
int cnt = 0;
int mx = -99999;
int mn = 999999999;
int b[4];
vector <int> a;

void DFS(int x,int temp)
{
	if (x==N)
	{
		if (mx < temp)
		{
			mx = temp;
		}
		if (mn > temp)
		{
			mn = temp;
		}
	}
	else//for문 쓰는게 아니라 따로 해야한다.
	{
		if (b[0]>0)
		{
			b[0]--;
			DFS(x + 1, temp+a[x]);
			b[0]++;
		}
		if (b[1] > 0)
		{
			b[1]--;
			DFS(x + 1, temp - a[x]);
			b[1]++;
		}
		if (b[2] > 0)
		{
			b[2]--;
			DFS(x + 1, temp * a[x]);
			b[2]++;
		}
		if (b[3] > 0)
		{
			b[3]--;
			DFS(x + 1, temp / a[x]);
			b[3]++;
		}
	}
}

int main(void)
{
	int now = 1;
	int x, y;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d",&x);
		a.push_back(x);
	}
	for (int i = 0; i < 4;i++)
	{
		scanf("%d", &b[i]);
	}

	DFS(1,a[0]);//1부터 시작

	printf("%d\n%d", mx,mn);
}
