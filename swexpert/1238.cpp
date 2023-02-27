/*
문제 : Contact
시간 : 1시간
ide 활용 : x
질문 보기 : x
피드백 : bfs로 전체를 찾기는 하는데 각 단계를 어떻게 해야하나 고민을 엄청 했다.
결국에는 queue에 stage라는 단계를 줘서 임의의 벡터에 stage마다 값을 푸쉬해서 마지막 stage를 저장시키고 해당 index 벡터의 최대값을 출력했다.

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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void)
{
	int test_case;
	int t;
	int T;
	int n;
	int start;
	queue<pair<int,int>> q;

	int a, b;
	freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		scanf("%d %d", &n, &start);
		int ans = 0;
		vector<int> arr[101];
		int vit[101] = { 0 };
		for (int i = 0; i < n/2; i++)
		{
			scanf("%d %d", &a, &b);
			arr[a].push_back(b);
		}

		q.push(make_pair(start,0));
		vit[start] = 1;
		vector<int> temp[101];
		while (!q.empty())
		{
			int now = q.front().first;
			int stage = q.front().second;
			ans = max(ans, stage);
			temp[stage].push_back(now);
			q.pop();
			for (int i = 0; i < arr[now].size(); i++)
			{
				if (vit[arr[now][i]] == 1)
					continue;

				q.push(make_pair(arr[now][i],stage+1));
				vit[arr[now][i]] = 1;
			}
		}
		printf("#%d %d\n", test_case,*max_element(temp[ans].begin(),temp[ans].end()));
	}
}
