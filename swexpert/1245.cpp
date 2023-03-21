/*
문제 :균형점
시간 : 50
ide 활용 : x
질문 보기 : x
피드백 : 처음에는 수학적으로 풀려고 접근햇는데 방정식은 세워지지만 코드를 표현하기가 힘들어
다른 방법을 생각하다가 이분탐색으로 하나씩 찾으면 어떻게 될까 궁금해서 실행하니 정답이 됐다.
mid를 업데이트를 할 때 소숫점 12자리까지 정확해야기 때문에 소숫점 12자리만큼 더하고 빼줫다.
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
#include <stack>

using namespace std;

int main(void)
{
	int T;
	int n;
	int now;

	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		double arr[11] = { 0 };
		double gra[11] = { 0 };
		scanf("%d", &n);


		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &arr[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf", &gra[i]);
		}
		printf("#%d ", test_case);
		for (int i = 1; i < n; i++)
		{
			
			//int  = 0;

			double left = arr[i];
			double right = arr[i + 1];
			double ans = (left + right)/2;

			while (left< right)
			{
				double front = 0;
				double back = 0;
				for (int j = 1; j <= i; j++)
				{
					front +=( gra[j] / ((ans - arr[j])*(ans - arr[j])));
				}
				for (int j = i + 1; j <= n; j++)
				{
					back += (gra[j] / ((ans - arr[j])*(ans - arr[j])));
				}
				if (front > back)
				{
					left = ans+0.000000000001;
				}
				else if (front < back)
				{
					right = ans - 0.000000000001;
				}
				else
				{
					break;
				}
				ans = (left + right) / 2;
			}
			printf("%.10lf ", ans);
		}
		printf("\n");
	}
}
