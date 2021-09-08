#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
int main(void)
{
	int x;
	int now = 0;
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		x = q.front();
		q.pop();
		now++;
		if (now == M)
		{
			now = 0;
			continue;
		}
		q.push(x);
	}
	printf("%d", x);

}
