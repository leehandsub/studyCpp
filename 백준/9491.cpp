/*
문제 : 백준 파도반 수열

시간 : 5분
ide 활용 : x
질문 보기 : x
피드백 : 자료형 때문에 틀려 부렸다.
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

long long arr[101];

int main(void)
{
	int n;
	int t;
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		arr[i] = arr[i - 5] + arr[i - 1];
	}
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		printf("%lld\n", arr[t]);
	}
}