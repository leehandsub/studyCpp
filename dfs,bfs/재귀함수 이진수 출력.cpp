#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int num)
{
	if (num == 1)
	{
		printf("%d", num);
		return;
	}
	dfs(num / 2);
	printf("%d", num%2);

}

int main(void)
{
	int N;
	int now;
	scanf("%d",&N);
	dfs(N);
}
