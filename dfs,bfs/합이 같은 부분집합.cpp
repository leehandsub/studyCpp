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
//다른 방법으로는 토탈을 구하고 반대껄 뺴면서 확인하면 굳이 배열 2개 안써도 됨...
/*#include<stdio.h>
int n, a[11], total = 0;
bool flag = false;
void DFS(int L, int sum) {
	if (sum > (total / 2)) return;
	if (flag == true) return;
	if (L == n + 1) {
		if (sum == (total - sum)) {
			flag = true;
		}
	}
	else {
		DFS(L + 1, sum + a[L]);
		DFS(L + 1, sum);
	}
}
int main() {
	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		total += a[i];
	}
	DFS(1, 0);
	if (flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}*/
