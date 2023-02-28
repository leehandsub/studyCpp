/*
문제 :등산로 조성
시간 : 45분
ide 활용 : x
질문 보기 : o
피드백 : 그냥 완탐으로 풀었따. 제일 높은것을 찾은 후 k만큼 뺀 것을 dfs로 찾은 후
최대값을 구햇다.
문제는 1~k까지인데 k만 빼서 49/51이 처음에 나왔다. 질문을 보고 해결했다.
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

int arr[9][9];
int n, k;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int maxCnt = -1;

void dfs(int y,int x,int now)
{
	maxCnt = max(maxCnt, now);
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= n || ny >= n || nx < 0 || ny < 0)
			continue;
		if (arr[y][x] <= arr[ny][nx])
			continue;
		dfs(y + dy[i], x + dx[i],now+1);
	}
}

int main(void)
{
	int T;

	int now;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d", &n,&k);
		int ans = -1;
		int maxNum = -1000;
		vector<pair<int, int>> maxArr;
		for(int i=0;i<n;i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
				if (maxNum < arr[i][j])
				{
					maxNum = arr[i][j];
					maxArr.clear();
					maxArr.push_back(make_pair(j, i));
				}
				else if(maxNum==arr[i][j])
					maxArr.push_back(make_pair(j, i));
			}
		}

		for (int i = 0; i < maxArr.size(); i++)//자기 자신일때, -k를 안할때?
		{
			for (int m = k; m >= 1; m--)
			{
				for (int j = 0; j < n; j++)
				{
					for (int l = 0; l < n; l++)
					{
						if (j != maxArr[i].second || l != maxArr[i].first)
						{
							arr[j][l] -= m;
						}
						dfs(maxArr[i].second, maxArr[i].first, 0);

						ans = max(ans, maxCnt);
						maxCnt = -1;
						if (j != maxArr[i].second || l != maxArr[i].first)
						{
							arr[j][l] += m;
						}
					}
				}
			}
		}

		printf("#%d %d\n", test_case, ans+1);

	}
}
