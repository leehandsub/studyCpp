#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int sum = 0;
	int N, M;
	scanf("%d", &N);
	//scanf("%d", &M);

	for (int i = 1; i < N; i++)
	{
		if (N % i == 0)
		{
			sum += i;
		}
	}
	printf("%d", sum);

}
