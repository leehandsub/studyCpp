/*
문제 : 기본 bfs
시간 : 40분?
ide 활용 : o
질문 보기 : x
피드백 : stl없이 짜다보니 시간이 오래걸리고 디버깅도 많이 해서 시간이 오래걸림 
현타가 좀 온다...

*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct Data {
	int x;
	int y;
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int arr[11][11];
int vit[11][11];

int s;


void bfs_init(int map_size, int map[10][10]) {

	s = map_size;
	for (int i = 1; i <= map_size; i++)
	{
		for (int j = 1; j <= map_size; j++)
		{
			arr[i][j] = map[i - 1][j - 1];
			vit[i][j] = 0;
		}
	}
}

int bfs(int x1, int y1, int x2, int y2) {
	int ans = -1;
	Data q[101];
	int front=0;
	int back=0;
	q[back++] = Data{ y1, x1 };
	vit[y1][x1] = 1;
	while (back != front)
	{
		int y = q[front].x;
		int x = q[front].y;
		front++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || nx > s || ny <= 0 || ny > s || arr[ny][nx] == 1 || vit[ny][nx] != 0)
				continue;
			q[back++] = Data{ ny, nx };
			vit[ny][nx] = vit[y][x] + 1;
			if (ny == y2 && nx == x2)
				ans = vit[ny][nx] - 1;
		}
	}
	for (int i = 1; i <= s; i++)
	{
		for (int j = 1; j <= s; j++)
		{
			vit[i][j] = 0;
		}
	}
	return ans;
}

