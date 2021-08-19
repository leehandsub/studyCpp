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
	int min = 9999;
	int flag = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}


	for (int i = 0; i < N-1; i++)
	{
		idx = i;
		for (int j = i+1; j < N; j++)
		{
			if (a[j] > a[idx])idx = j;
		}
		int temp = a[i];
		a[i] = a[idx];
		a[idx] = temp;
	}
	for (int i = 0; i < N; i++)
	{
		if (min > a[i])
		{
			flag++;
			min = a[i];
		}
		if (flag == 3)
		{
			break;
		}
	}
	printf("%d", min);

}
//slection sort
