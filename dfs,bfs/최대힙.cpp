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
				a[b++] = q.top();
				q.pop();
			}
		}
		else
		{
			q.push(x);
		}
	}
	for (int i = 0; i < b; i++)
	{
		printf("%d\n", a[i]);
	}

}//maxheap... 부모가 자식보다 커야한다. 루트에 항상 최댓값이 저장되있음
// 7.. 6을 참조하면 맨뒤에 있는 거하고 바꾸고 다시 maxheap으로 바꾼다.
