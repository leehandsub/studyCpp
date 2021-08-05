#include <stdio.h>
#include <iostream>

int main(void)
{
	int sum = 0;
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = 1; i <= N; i++)
	{
		if (i % M == 0)
		{
			sum += i;
		}
	}
	printf("%d", sum);

}