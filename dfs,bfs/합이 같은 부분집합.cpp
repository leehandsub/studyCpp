#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int arr2[11];
int arr[11];
int N;
int flag = 0;
void part(int n)
{
	int a = 0 , b = 0;
	if (n == N ) {
		for (int i = 0; i < N; i++)
		{
			if (arr2[i] == 1)
			{
				a += arr[i];
			}
			else
			{
				b += arr[i];
			}
		}
		if (a == b)
		{
			flag = 1;
		}
	}
	else
	{
		arr2[n] = 1;
		part(n + 1);
		arr2[n] = 0;
		part(n +1);
	}
}

int main(void)
{
	int now;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	part(0);
	if (flag == 1)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}

}
