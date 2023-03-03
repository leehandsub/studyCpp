/*
문제 :인구 이동
시간 : 30분
ide 활용 : x
질문 보기 : x
피드백 : 그냥 완탐으로 풀었다.
모든 배열을 돌면서 조건에 맞는 경우가 나오면 bfs를 해서 탐색했다.
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

int arr[51][51];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	int n, l, r;
	int cnt = 0;

	scanf("%d %d %d", &n, &l, &r);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	while (1)
	{
		int vit[51][51] = { 0 };
		int flag = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (vit[i][j] == 0)
				{
					vector<pair<int, int>> temp;
					queue<pair<int, int>> q;
					int total = 0;
					q.push(make_pair(j, i));//x,y
					vit[i][j] = 1;
					temp.push_back(make_pair(j, i));
					total += arr[i][j];
					while (!q.empty())
					{
						int x = q.front().first;
						int y = q.front().second;
						q.pop();

						for (int k = 0; k < 4; k++)
						{
							int nx = x + dx[k];
							int ny = y + dy[k];
							if (nx >= n || nx < 0 || ny >= n || ny < 0 || vit[ny][nx] == 1)
								continue;
							if (abs(arr[y][x] - arr[ny][nx]) < l || abs(arr[y][x] - arr[ny][nx]) > r)
								continue;
							q.push(make_pair(nx, ny));
							vit[ny][nx] = 1;
							temp.push_back(make_pair(nx, ny));
							total += arr[ny][nx];
						}
					}
					if (temp.size() > 1)
					{
						flag = 0;
					}
					for (int k = 0; k < temp.size(); k++)
					{
						arr[temp[k].second][temp[k].first] = total / temp.size();
					}
				}
				
			}
		}
		if (flag == 0)
			cnt++;
		else
			break;
	}
	printf("%d", cnt);
}
