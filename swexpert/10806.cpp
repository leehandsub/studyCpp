/*
문제 : swea 수 만들기
시간 : 20분
ide 활용 : x
질문 보기 : o
피드백 : 이번 문제는 pq를 이용해서 제일 작은 값을 계속 확인하며 문제를 풀었다.
문제를 이해못해 질문을 봤다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[11];

int main()
{
	int T;
	int n;
	int k;
	int ans = 0;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", & arr[i]);
		}
		scanf("%d", &k);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push(make_pair(0, k));
		while (!pq.empty())
		{

			int cnt = pq.top().first;
			int now = pq.top().second;
			if (now == 0)
			{
				ans = cnt;
				break;
			}
			pq.pop();
			pq.push(make_pair(cnt + now, 0));
			for (int i = 0; i < n; i++)
			{
				pq.push(make_pair(cnt + now % arr[i],now / arr[i]));
			}
		}
		printf("#%d %d\n", t, ans);
	}
	
}