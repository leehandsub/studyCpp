#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int arr[11];
int N;
void part(int n)
{
	if (n == N + 1) {
		for (int i = 0; i < N; i++)
		{
			if (arr[i] == 1)
			{
				printf("%d ", i + 1);
			}
		}
		puts("");
	}
	else
	{
		arr[n-1] = 1;
		part(n + 1);
		arr[n-1] = 0;
		part(n +1);
	}
}

int main(void)
{
	int now;
	scanf("%d", &N);
	part(1);

}
