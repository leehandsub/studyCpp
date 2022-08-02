/*
문제 : swea 파핑파핑 지뢰찾기
시간 : 40분
ide 활용 : x
질문 보기 : o
피드백 : 문제를 이해못해서 이리저리 많이 찾아봣다.
일단 먼저 0인 부분을 모두찾고 그와 관련된 것들을 모두 bfs로 방문표시를 했다.
한 번 순회를 다한다음 다시한번 순회를 하며 지뢰가 아니거나 방문을 안했으면 cnt++을 해줬다.

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

char arr[301][301];
int vit[301][301];
int num;

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };

int findZ(int i, int j)
{
	int x, y;
	for (int k = 0; k < 8; k++)
	{
		x = j + dx[k];
		y = i + dy[k];
		if (x < 0 || x >= num || y < 0 || y >= num)
			continue;
		if (arr[y][x] == '*')
			return 0;
	}
	return 1;
}

int main(void)
{
	int T;
	char c;
	int x, y;
	queue<pair<int, int>> q;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 1; t <= T ; t++)
	{
		scanf("%d", &num);
		int cnt = 0;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				scanf(" %c", &arr[i][j]);
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (arr[i][j] == '.')
				{
					if (findZ(i, j) == 1&&vit[i][j]==0)
					{
						cnt++;
						q.push(make_pair(i, j));
						vit[i][j] = 1;
						while (!q.empty())
						{
							x = q.front().second;
							y = q.front().first;
							q.pop();
							if (findZ(y, x) == 0)
								continue;
							for (int k = 0; k < 8; k++)
							{
								int nx = x + dx[k];
								int ny = y + dy[k];
								if (nx < 0 || nx >= num || ny < 0 || ny >= num||vit[ny][nx]==1)
									continue;
								q.push(make_pair(ny, nx));
								vit[ny][nx] = 1;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (vit[i][j] == 0 && arr[i][j] == '.')
					cnt++;
			}
		}
		printf("#%d %d\n", t, cnt);
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				vit[i][j] = 0;
			}
		}
	}
}