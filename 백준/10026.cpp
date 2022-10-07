/*
문제 : 적록색약
시간 : 20분
ide 활용 : o
질문 보기 : x
피드백 : ny 제한을 잘못해서 큰일날뻔
bfs를 사용했다.
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

char arr[101][101];
int vit[101][101];
int vit2[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void)
{
	int n;
	int t;
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	int b=0;
	int gr=0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", arr[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<n;j++)
		{
			if (vit[i][j] == 0)//정상
			{
				b++;
				q.push(make_pair(i, j));
				vit[i][j] = 1;
				while (!q.empty())
				{
					int x = q.front().second;
					int y = q.front().first;
					q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || vit[ny][nx]==1)
							continue;
						if (arr[y][x] != arr[ny][nx])
							continue;
						q.push(make_pair(ny, nx));
						vit[ny][nx] = 1;
					}
				}
			}
			if (vit2[i][j] == 0)//적록색약
			{
				gr++;
				q2.push(make_pair(i, j));
				vit2[i][j] = 1;
				while (!q2.empty())
				{
					int x = q2.front().second;
					int y = q2.front().first;
					q2.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n || vit2[ny][nx]==1)
							continue;
						if (arr[y][x] == 'B')
						{
							if (arr[ny][nx]!=arr[y][x])
								continue;
						}
						else
						{
							if (arr[ny][nx] == 'B')
								continue;
						}
						q2.push(make_pair(ny, nx));
						vit2[ny][nx] = 1;
					}
				}
			}
		}
	}

	printf("%d %d", b, gr);
}