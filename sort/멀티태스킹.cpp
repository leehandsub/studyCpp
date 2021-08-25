#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	int sum = 0;
	int find = 0;
	int cnt = 0;
	int start = 0;
	int i = 1;
	int now = 0;
	scanf("%d", &N);
	vector<int> a(N+1);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &find);
	while (now!=find)
	{
		if (a[i] != 0)
		{
			a[i]--;
			now++;
		}
		else
		{
		
		}

		if (i % N == 0)
		{
			i = 0;
		}
		i++;

	}
	start = i;
	for (int i = start; i <= N; i++)
	{
		if (a[i] != 0)
		{
			printf("%d", i);
			return 0;
		}
	}
	for (int i = 1; i < start; i++)
	{
		if (a[i] != 0)
		{
			printf("%d", i);
			return 0;
		}
	}

	printf("-1");

}
