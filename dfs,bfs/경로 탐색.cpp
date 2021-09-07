#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[21][21];
int check[21];
int cnt = 0;
void dfs(int v)
{
	if (v == N - 1)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (arr[v][i] == 1&&check[i]==0)
			{
				check[i] = 1;
				dfs(i);
				check[i] = 0;
			}
		}
	}
}

int main(void)
{
	int a, b;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		arr[a-1][b-1]=1;
	}
	check[0] = 1;
	dfs(0);
	printf("%d", cnt);
	
}//2차원 배열 사용
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int check[30];
vector <int> a[30];
int cnt;
int N;
void dfs(int x)
{
	if (x == N)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < a[x].size(); i++)
		{
			if (check[a[x][i]]==0)
			{
				check[a[x][i]] = 1;
				dfs(a[x][i]);
				check[a[x][i]] = 0;
			}
		}
	}
}

int main(void)
{
	int M;
	int c, d;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &c, &d);
		a[c].push_back(d);
	}
	check[1] = 1;
	dfs(1);
}*/
//vector 사용
