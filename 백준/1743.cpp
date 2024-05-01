/*
문제 :음식물 피하기
시간 :20분
ide 활용 : o
질문 보기 : X
피드백 : 그냥 단순 bfs 문제이다. 자꾸 bfs할떄마다 실수를해서 큰일이긴하다ㅋㅋㅋ
그래서 조금 오래걸림
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

int dx[4] = { 1,0, - 1,0 };
int dy[4] = { 0,-1,0,1 };

int arr[101][101];
int vit[101][101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m,k;
	int ans = 0;
	int a, b;

	cin >> n >> m>>k;

	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1&&vit[i][j]==0)
			{
				queue<pair<int, int>> q;
				vit[i][j] = 1;
				q.push({ j,i });
				int now = 0;
				while (!q.empty())
				{
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					now++;
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= m || nx < 0 || ny >= n || ny < 0 || vit[ny][nx] == 1)
							continue;
						if (arr[ny][nx] == 0)
							continue;

						q.push({ nx,ny });
						vit[ny][nx] = 1;
					}
				}
				
				ans = max(ans, now);
			}
		}
	}

	cout << ans;
	
}
