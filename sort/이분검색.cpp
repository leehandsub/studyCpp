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
	int right, left=0, mid;
	int cnt = 0;
	int k = 0, j = 0;
	int num;
	scanf("%d %d", &N, &find);
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	right = N - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == find)
		{
			printf("%d", mid + 1);
			return 0;
		}
		else if (a[mid] >= find)
		{
			right=mid- 1;
		}
		else
		{
			left = mid + 1;
		}
	}
}
//binary search
