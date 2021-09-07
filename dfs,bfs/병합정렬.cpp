#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int a[101];
int temp[101];
void divide(int left, int right)
{
	int mid;
	int p1, p2, p3;
	if (left < right)
	{
		mid = (left + right) / 2;
		divide(left, mid);// 
		divide(mid+1, right);
		p1 = left;
		p2 = mid + 1;
		p3 = left;
		while (p1<=mid&&p2<=right)
		{
			if (a[p1] < a[p2])
			{
				temp[p3++] = a[p1++];
			}
			else temp[p3++] = a[p2++];
		}
		while (p1 <= mid)temp[p3++] = a[p1++];//끝까지 넣기
		while (p2 <= right)temp[p3++] = a[p2++];//끝까지 넣기
		for (int i = 0; i <= right; i++)
		{
			a[i] = temp[i];
		}
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	divide(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d",a[i]);
	}
	
}
//병합정렬(분할 정복)
//39 두배열 합치기 참고
