#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int a[101] = { 0 };
	int b[101] = { 0 };
	int c[201] = { 0 };
	int N, M;
	int flag;
	int k = 0, j = 0;
	int num;
	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N + M; i++)
	{
		if (k == M)
		{
			c[i] = a[j++];

		}
		else if (j == N)
		{
			c[i] = b[k++];
		}
		else if (a[j] > b[k])
		{
			c[i] = b[k++];
		}
		else
		{
			c[i] = a[j++];
		}

	}
	for (int i = 0; i < N + M; i++)
	{
		printf("%d ", c[i]);
	}
}
