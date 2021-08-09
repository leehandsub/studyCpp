#include <stdio.h>
#include <iostream>
using namespace std;

int digit_sum(int n)
{
	int sum = 0;
	int big = 10000000;
	for (int i = 1; i <= 8; i++)
	{
		sum += n / big;
		n = n % big;
		big /= 10;
	}
	return sum;
}

int main(void)
{
	int cnt[64] = { 0 };
	int N, num, max = 0,now=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		now = digit_sum(num);
		if (cnt[now] != 0&&cnt[now]>num)//여기서 너무 시간 먹엇다
		{
			continue;
		}
		cnt[now] = num;
		if (max < now)
		{
			max = now;
		}

	}
	printf("%d", cnt[max]);
}
