#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int now = 1;
	int min = 9999;
	int a[1501] = { 0 };
	scanf("%d", &N);
	int p2=1, p3=1, p5 = 1;
	a[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		if (a[p2] * 2 < a[p3] * 3)
		{
			min = a[p2] * 2;
		}
		else
		{
			min = a[p3] * 3;
		}
		if (a[p5] * 5 < min)
		{
			min = a[p5] * 5;
		}
		if (a[p2] * 2 == min)p2++;
		if (a[p3] * 3 == min)p3++;
		if (a[p5] * 5 == min)p5++;
		a[i] = min;
	}

	printf("%d", a[N]);

}//투포인트 활용 나중에 다시 해봐야할지도...
