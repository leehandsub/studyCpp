#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int dis = 1;
	int big = 10;
	for (int i = 1; i <= N; i++)
	{
		if (i == big)
		{
			dis++;
			big *= 10;
		}
		sum += dis;
	}
	printf("%d", sum);

}
