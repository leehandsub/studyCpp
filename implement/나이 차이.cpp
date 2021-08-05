#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
//	int sum = 0;
	int min = 999, max = 0;
	int N, M;
	scanf("%d", &N);
	//scanf("%d", &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &M);
		if (min > M)
		{
			min = M;
		}
		if (max < M)
		{
			max = M;
		}

	}
	printf("%d", max-min);

}
