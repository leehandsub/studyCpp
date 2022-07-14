/*
문제 : 백준 토마토
시간 : 50분
ide 활용 : o
질문 보기 : o
피드백 : 처음에 제대로 풀엇는데 디버깅하다 쉽게한다고 max값을 6으로 줘서 계속 시간초과 발생
20분정도 삽질하다가 발견하고 모두 -1일 때 경우를 생각안해서 마지막으로 고쳤다.
엣지 케이스를 생각하는 습관을 기르긴 해야겠다.

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
#include <unordered_map>
#include <algorithm>

using namespace std;

int arr[101][101][101];
int vit[101][101][101];

int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,-1,0,1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };

typedef struct tomato
{
	int z;
	int y;
	int x;
	int cnt;
}tomato;

int main(void)
{
	int n, m, h;
	int num = 0;
	scanf("%d %d %d", &n, &m, &h);
	int ans = 0;
	queue<tomato> q;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 1)
				{
					q.push(tomato{ i,j,k,0 });
					vit[i][j][k] = 1;
				}
				else if (arr[i][j][k] == 0)
					num++;
			}
		}
	}
	if (q.empty())
	{
		printf("-1");
		return 0;
	}

	while (!q.empty())
	{
		tomato now = q.front();
		q.pop();
		for (int l = 0; l < 6; l++)
		{
			int nz = now.z + dz[l];
			int ny = now.y + dy[l];
			int nx = now.x + dx[l];
			int ncnt = now.cnt + 1;
			if (nz < 0 || nz >= h || ny < 0 || ny >= m || nx < 0 || nx >= n)
				continue;
			if (vit[nz][ny][nx] == 1 || arr[nz][ny][nx] != 0)
				continue;
			q.push(tomato{ nz, ny, nx,ncnt });
			vit[nz][ny][nx] = 1;
			ans = ncnt;
			num--;
		}
	}
	if (num == 0)
		printf("%d", ans);
	else
		printf("-1");
}