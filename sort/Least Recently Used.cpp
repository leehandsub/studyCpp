#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int a[20] = { 0 };
	int N, M;
	int flag;
	int j;
	int num;
	scanf("%d %d", &N,&M);


	for (int i = 1; i <= M; i++) {
		scanf("%d", &num);
		flag = -1;
		for (int j = 0; j < N; j++) if (a[j] == num) flag = j;
		if (flag == -1) {
			for ( j = N - 1; j >= 1; j--) a[j] = a[j - 1];
		}
		else {
			for ( j = flag; j >= 1; j--) a[j] = a[j - 1];
		}
		a[j] = num;
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

}
