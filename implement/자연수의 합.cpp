#include <stdio.h>
#include <iostream>

int main(void)
{
	int sum = 0;
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);

	for (int i = N; i <= M; i++)
	{
		sum += i;
	}
	printf("%d", sum);

}
