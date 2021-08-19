#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int idx = 0;
	int cnt = 0;
	int a[500];
	int num = 0;


	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}


	for (int i = 0; i < N-1; i++)
	{
		idx = i;
		for (int j = 0; j < N; j++)
		{
			if (a[j] < a[idx])idx = j;
		}
		int temp = a[i];
		a[i] = a[idx];
		a[idx] = a[i];
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

}
//slection sort