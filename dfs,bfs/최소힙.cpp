#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int> q;
int main(void)
{
	int x;
	int now = 0;
	int N, M;
	int b = 0;
	int a[100];

	while (1)
	{
		scanf("%d", &x);
		if (x == -1)
		{
			break;
		}
		if (x == 0)
		{
			if (q.empty())printf("-1\n");
			else
			{
				a[b++] = -q.top();
				q.pop();
			}
		}
		else
		{
			q.push(-x);//작은값이 루트로 간다.
		}
	}
	for (int i = 0; i < b; i++)
	{
		printf("%d\n", a[i]);
	}

}//minheap... 힙에는 -로 다 바꿔서 만들고 실제로 계산할때는 +로바꿔서 계산
