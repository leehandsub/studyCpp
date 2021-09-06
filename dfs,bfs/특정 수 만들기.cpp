#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
int a[11];
int cnt;
void dfs(int n,int sum)
{
	if (n == N-1)
	{
		if (M == sum)
		{
			cnt++;
		}
	}
	else
	{
		dfs(n + 1, sum+a[n]);
		dfs(n + 1, sum - a[n]);
		dfs(n + 1, sum);
	}
}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	dfs(-1,0);
	if (cnt == 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d", cnt);
	}
}


/*int N, M;
int cnt = 0;
int a[11];
int b[11];
void dfs(int n, int sum)
{
	if (n == N)
	{
		return;
	}
	else
	{
		b[n] = 1;
	}
	if (b[n] == 1)
	{
		sum += a[n];
	}
	else
	{
		sum -= a[n];
	}
	if (sum == M)
	{
		cnt++;
	}

	dfs(++n,sum );
	b[n] = 0;
	dfs(++n, sum);

}

int main(void)
{
	int now;
	int sum = 0;
	scanf("%d %d", &N,&M);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++)
	{
		dfs(i,0);
	}

	printf("%d", cnt);
}*/
// 내처음 생각은 실시간으로 sum을 체크하는거였다. n+1 n++차이...
// 강의에는 + = 없다로 나누어 풀엇다....
