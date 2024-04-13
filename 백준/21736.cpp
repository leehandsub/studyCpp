/*
문제 :헌내기는 친구가 필요해
시간 :10분
ide 활용 : x
질문 보기 : x
피드백 : 단순한 bfs문제이다 
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


int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

char arr[601][601];
int vit[601][601];

int main(void)
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

	int n, m;
	queue<pair<int, int>> q;

	cin >> n >> m;
	
	int start_x, start_y;
	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf(" %1c", &arr[i][j]);
			if (arr[i][j] == 'I')
			{
				q.push({ j,i });
				vit[i][j] = 1;
			}
		}
	}
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (arr[y][x] == 'P')
			ans++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= m || nx < 0 || ny >= n || ny < 0 || vit[ny][nx] == 1)
				continue;

			if (arr[ny][nx] == 'X')
				continue;

			q.push({ nx,ny });
			vit[ny][nx] = 1;
		}
	}

	if (ans == 0)
		cout << "TT";
	else
		cout << ans;

}
