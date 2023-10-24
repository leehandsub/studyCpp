/*
문제 : 미세먼지 안녕! 
시간 : 2시간
ide 활용 : o
질문 보기 : x
피드백 : 단순 시뮬인데 문제를 이해 못한것도 있고 오래만에 문제를 풀어서 그런지
엄청 오래걸렷다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<vector<int>> arr(50, vector<int>(50));
int r, c, t;

typedef struct NODE
{
	int x, y, val;
	NODE(int _x, int _y, int _val) {
		x = _x;
		y = _y;
		val = _val;
	}
}NODE;

void clearDust(int iy,int ix,int zx[4],int zy[4])
{
	queue<int> q;
	int flag = 0;
	int x = ix + 1;
	int y = iy;
	q.push(arr[y][x]);
	arr[y][x] = 0;
	while (1)
	{
		x += zx[flag];
		y += zy[flag];

		if (x >= c || x < 0 || y >= r || y < 0)
		{
			x -= zx[flag];
			y -= zy[flag];
			flag++;
		}
		else
		{
			q.push(arr[y][x]);
			int now = q.front();
			if (arr[y][x] == -1)
				break;
			arr[y][x] = now;
			q.pop();
		}
	}
}

int main(void)
{

	int sx=0, sy=0;
	int lx=0, ly=0;
	int sum = 0;

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == -1&&sy==0)
			{
				sy = i;
				sx = j;
			}
			else if (arr[i][j] == -1&&sy!=0)
			{
				ly = i;
				lx = j;
			}
		}
	}

	while (t--) 
	{
		vector<NODE> dust;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (arr[i][j] != 0 && arr[i][j] != -1)
				{
					dust.push_back(NODE{ j,i ,arr[i][j]});
				}

			}
		}// 확산

		for (int i = 0; i < dust.size(); i++)
		{
			int cnt = 0;
			int x = dust[i].x;
			int y = dust[i].y;
			int val = dust[i].val;
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx >= c || nx < 0 || ny >= r || ny < 0) continue;

				if (arr[ny][nx] == -1) continue;

				arr[ny][nx] += floor(val / 5);//빼놓고 해놔서 안되네 //올림되는거 같은 느낌
				cnt++;
			}
			int temp = floor(val / 5);
			arr[y][x] -= temp*cnt;

		}	

		int zx[4] = { 1,0,-1,0 };
		int zy[4] = { 0,-1,0,1 };
		clearDust(sy, sx, zx, zy);
		int ldx[4] = { 1,0,-1,0 };
		int ldy[4] = { 0,1,0,-1 };
		clearDust(ly, lx, ldx, ldy);
	}


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if(arr[i][j]!=-1)
				sum += arr[i][j];
		}
	}

	cout << sum;

}
