#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	int sum = 0;
	int find = 0;
	int cnt = 0;
	int res = 0;
	int i = 0;
	int num;
	scanf("%d %d", &N, &find);
	vector<int> a(N + 1);
	while (sum!=N-1){
		i++;
		if (a[i] == 0)
		{
			cnt++;
		}
		if (cnt % find == 0&&cnt!=0)
		{
			a[i] = 1;
			sum++;
			cnt = 0;
		}
		if (i % N == 0&&i!=0)
		{
			i = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (a[i] == 0)
		{
			printf("%d", i);
			break;
		}
	}
}//조세퍼스
