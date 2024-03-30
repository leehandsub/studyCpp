/*
문제 :두 동전
시간 :60분
ide 활용 : o
질문 보기 : X
피드백 : 단순 구현? 완탐이다.
bfs로 경우의 수를 나눠서 풀었따. nx,ny 등 변수등을 잘못 적어놓은게 많아서 좀 오래 걸렷다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

typedef struct NODE{
	int x, y, cnt;
	NODE(int _x, int _y, int _cnt)
	{
		x = _x;
		y = _y;
		cnt = _cnt;
	}
}NODE;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

char arr[21][21];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int ans = 199999999;

	cin >> n >> m;

	vector<NODE> coin;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'o')
			{
				coin.push_back(NODE(j,i,0));
			}
		}
	}

	queue<NODE> q;
	q.push(NODE(coin[0].x,coin[0].y,coin[0].cnt));
	q.push(NODE(coin[1].x, coin[1].y, coin[1].cnt));

	while (!q.empty())
	{
		int one_x = q.front().x;
		int one_y = q.front().y;
		int one_cnt = q.front().cnt;
		q.pop();
		int two_x = q.front().x;
		int two_y = q.front().y;
		int two_cnt = q.front().cnt;
		q.pop();
		if (one_cnt >= 10)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int one_nx = one_x + dx[i];
			int one_ny = one_y + dy[i];
			int two_nx = two_x + dx[i];
			int two_ny = two_y + dy[i];
			int one_flag = 0;
			int two_flag = 0;
			if (one_nx >= m || one_nx < 0 || one_ny >= n || one_ny < 0)
			{
				one_flag = 1;
			}

			if (two_nx >= m || two_nx < 0 || two_ny >= n || two_ny < 0)
			{
				two_flag = 1;
			}
			if (one_flag == 1 && two_flag == 1)
				continue;
			if ((one_flag ^ two_flag )== 1)
			{
				ans = min(ans, one_cnt+1);
			}
			else
			{
				if (arr[one_ny][one_nx] == '#')
				{
					q.push(NODE(one_x, one_y, one_cnt + 1));
				}
				else
				{
					q.push(NODE(one_nx, one_ny, one_cnt + 1));
				}
				if (arr[two_ny][two_nx] == '#')
				{
					q.push(NODE(two_x, two_y, two_cnt + 1));
				}
				else
				{
					q.push(NODE(two_nx, two_ny, two_cnt + 1));
				}
			}
		}
	}
	if (ans == 199999999)
		ans = -1;
	cout << ans;

}
