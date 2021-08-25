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
	int right=0, left=1, mid;
	int cnt = 1;
	int res = 0;
	int k = 0, j = 0;
	int num;
	scanf("%d %d", &N, &find);
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
		right += a[i];
	}
	
	while (left <= right)
	{
		mid = (left + right) / 2;
		
		for (int i = 0; i < N; i++)
		{
			if (sum+a[i] > mid)
			{
				cnt++;
				sum = 0;
			}
			sum += a[i];
		}//dvd갯수가 맞냐?
		if (cnt <= find)
		{
			res = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		cnt = 1;
		sum = 0;
	}
	printf("%d", res);
}
//Decision Tree
//먼저 1~끝까지 합의 분을 구한다. 이분 탐색으로 최적의 시간을 구한다.
