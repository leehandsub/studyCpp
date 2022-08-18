/*
문제 : swea 사칙연산 유효성 검사
시간 : 30분
ide 활용 : o
질문 보기 : o
피드백 : 문제를 이해 못해서 질문을 참고해서 풀었다.
굳이 트리를 안만들고 input으로 들어오는 것으로 판단해서 풀었다.
n/2==num인 부분에서 scanf를 두번해서 자꾸 이상하게 나왔다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	int num;
	char c;
	int x, y;
	int n;
	freopen("input.txt", "r", stdin);
	//scanf("%d", &T);

	for (int t = 1; t <= 10; t++)
	{
		int flag = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			if (n / 2 >= num)
			{
				scanf(" %c", &c);
				if (c >= '0' && c <= '9')
				{
					flag = 0;
				}
				if (n / 2 == num && n % 2 == 0)
					scanf("%d", &x);
				else
					scanf("%d %d", &x, &y);

			}
			else
			{
				scanf(" %c", &c);
				if (c < '0' || c> '9')
				{
					flag = 0;
				}
			}
		}
		printf("#%d %d\n", t, flag);
	}
}