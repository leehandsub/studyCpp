/*
문제 : 쉬운 최단거리
시간 : 2시간
ide 활용 : o
질문 보기 : o
피드백 : 일단 그냥 bfs문제인데 오래만에 풀어서 그런지 시간이 너무 걸렷다
알고보니 queue에 x,y순으로 넣어야하는데 y,x순으로 넣어서 문제였다....
문제를 잘 읽지 않아 못가는 경우-1을 출력하는 것을 몰랏다.
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
#include <cstdio>

using namespace std;

typedef struct NODE {
	int x;
	int y;
	int dis;
	NODE(int X, int Y, int DIS)
	{
		x = X;
		y = Y;
		dis = DIS;
	}
};


int arr[1001][1001];
int vit[1001][1001];
int ans[1001][1001];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	int n, m;
		
	cin >> n>> m;
	int start_x = 0;
	int start_y = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				start_x = j;
				start_y = i;
			}
		}
	}
	
	queue<NODE> q;
	q.push(NODE(start_x,start_y,0));
	vit[start_y][start_x] = 1;

	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int dis = q.front().dis;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (ny >= n || ny < 0 || nx >= m || nx < 0 || vit[ny][nx] == 1)
				continue;

			if (arr[ny][nx] == 0)
				continue;

			vit[ny][nx] = 1;
			ans[ny][nx] = dis+1;
			q.push(NODE(nx, ny, dis + 1));
			
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(arr[i][j]==0)
				cout << 0 << " ";
			else if(vit[i][j]==0)
				cout << -1 << " ";
			else
				cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}
