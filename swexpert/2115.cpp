/*
문제 : 벌꿀채취
시간 : 2시간
ide 활용 : o
질문 보기 : x
피드백 : 먼저 가능한 모든 벌통을 구하고 조합으로 뽑는다.
그리고 뽑은 벌통내에서 부분집합으로 모든 경우의수를 구해서 최대값을 구한다.
다른 사람들의 시간이 훨씬 짧은걸 보아 다시 한번 풀어야겟다.
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
#include <math.h>

using namespace std;

int n, m, c;

int userVit[6];
int ma;

void init() {
	for (int i = 0; i < m; i++)
	{
		userVit[i] = 0;
	}
}

void dfs(vector<int> users, int level)
{
	if (level == m)
	{
		vector<int> tt;
		for (int i = 0; i < m; i++)
		{
			if (userVit[i] == 1)
				tt.push_back(users[i]);
		}
		int cnt = 0;
		int num = 0;
		for (int i = 0; i < tt.size(); i++)
		{
			cnt += tt[i];
			num += (tt[i] * tt[i]);
			if (cnt > c)
				return;
		}
		ma = max(ma, num);

	}
	else
	{
		userVit[level] = 1;
		dfs(users, level + 1);
		userVit[level] = 0;
		dfs(users, level + 1);
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
		scanf("%d %d %d", &n,&m,&c);
		int ans = 0;
		int arr[11][11];
		vector<vector<int>> beeList;
		vector<int> vit;

		for (int i = 0; i < n; i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d", &arr[i][j]);
			}
		}
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n - m; j++)
			{
				vector<int> user1;
				for (int k = 0; k < m; k++)
				{
					user1.push_back(arr[i][j + k]);
				}
				vit.push_back(0);
				beeList.push_back(user1);
			}
		
		}
		vit[0] = 1;
		vit[1] = 1;

		do {
			vector<int> users;
			int time = 0;
			for (int i = 0; i < beeList.size(); i++)
			{
				if (vit[i] == 1)
					users.push_back(i);
			}
			if ((users[0] + m > users[1]) && (users[0]/(n-m+1))==(users[1] / (n - m + 1)))
				continue;


			/*if (users[1] + m > n)
				continue;*/

			dfs(beeList[users[0]],0);
			time += ma;
			ma = 0;
			init();

			dfs(beeList[users[1]], 0);
			time += ma;
			ma = 0;
			init();

			ans = max(ans, time);

		} while (prev_permutation( vit.begin(), vit.end()));

		printf("#%d %d\n", test_case, ans);
	}
}
