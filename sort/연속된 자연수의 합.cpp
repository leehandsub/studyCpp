#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int a[60001] = { 0 };
	int N, M;
	int sum = 0;
	int flag=0;
	int cnt = 0;
	int k = 0, j = 0;
	int num;
	scanf("%d", &N);


	for (int i = 1; i <= N / 2 ; i++)
	{
		k = i;
		while (1)
		{
			if (sum > N)
			{
				break;
			}
			else if (sum == N)
			{
				cnt++;
				flag = 1;
				break;
			}
			sum += k;
			k++;
		}
		if (flag == 1)
		{
			for (int j = i; j < k-1; j++)
			{
				printf("%d+", j);
			}
			printf("%d=%d\n", k-1, N);
			flag = 0;
		}
		sum = 0;
	}

	printf("%d", cnt);

}
