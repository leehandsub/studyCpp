/*
문제 : 코드트리 빵
시간 : 2시간30분
ide 활용 : o
질문 보기 : o
피드백 : 단순 구현 문제이다.
예외로 처음 베이스캠프를 정하는데 거리만 짧고 못가는 경우가 있다.(2로 둘러싸임)
이러면 무한루프 돌아서 시간초과가 뜨는데 그래서 도착하면 값을 넣으라고 구현했다.질문참고
단순구현하면서 도착하는 곳이 2로 변해있을 수도 있는 예외상황도 있엇다.(이건 운좋게 찾앗다.)

!!	1.문제를 풀때 먼저 테케에 대한 그림을 그리자
	2.input을 잘봐야한다. 이번에도 x,y를 반대로 보고 2,2가 1,1로변환을 안함...
	3.시간초과 안돌거 같은데 시간초과면 꼭 무한반복을 의심하자
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
#include <math.h>

using namespace std;

struct Cood
{
	int x, y;
	Cood(int X, int Y) {
		x = X;
		y = Y;
	}
};
bool cmp(Cood a, Cood b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int dx[4] = { 0,-1,1,0 };//북서동남
int dy[4] = { -1,0,0,1 };

int n, m;
int arr[16][16];
int vit[16][16];
int ans = 0;

vector<Cood> baseList;
vector<Cood> conList;
vector<Cood> personPos;
vector<int> complete(31, 0);


void initVit()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vit[i][j] = 0;
		}
	}
}

int findBase(int t) 
{
	int mi = 1999999999;
	int idx = 0;

	for (int i = 0; i < baseList.size(); i++)//0번째 녀석 베이스캠프 찾기 n^4
	{
		int cnt = 0;
		int flag = 0;
		queue<Cood> q;
		q.push(Cood(conList[t].x, conList[t].y));
		vit[conList[t].y][conList[t].x] = 1;
		while (!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			cnt++;
			q.pop();
			if (x == baseList[i].x && y == baseList[i].y)
			{
				flag = 1;
				break;
			}
			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= n || nx<0 || ny >= n || ny < 0 || vit[ny][nx] == 1)
					continue;
				if (arr[ny][nx] == 2)
					continue;
				q.push(Cood(nx, ny));
				vit[ny][nx] = 1;
			}
		}

		if (mi > cnt&&flag==1)
		{
			mi = cnt;
			idx = i;
		}
		initVit();
	}

	arr[baseList[idx].y][baseList[idx].x] = 2;//벽 생성
	

	return idx;
}


Cood findPersonCon(int personIndex)//다음위치를 위해 거꾸로 bfs돈다.
{
	if (conList[personIndex].x == personPos[personIndex].x && conList[personIndex].y == personPos[personIndex].y)
		return Cood(conList[personIndex].x, conList[personIndex].y);
	queue<Cood> q;
	q.push(Cood(conList[personIndex].x, conList[personIndex].y));
	vit[conList[personIndex].y][conList[personIndex].x] = 1;
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int j = 3; j >= 0; j--)
		{
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= n || nx<0 || ny >= n || ny < 0 || vit[ny][nx] == 1)
				continue;
			if (nx == personPos[personIndex].x && ny == personPos[personIndex].y)
			{
				initVit();
				return Cood(x, y);
			}
			if (arr[ny][nx] == 2)
				continue;

			
			q.push(Cood(nx, ny));
			vit[ny][nx] = 1;
		}
	}
	initVit();
}

int main(void)
{
	int x, y;

	scanf("%d %d", &n, &m);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				baseList.push_back(Cood(j, i));
		}
	}

	for (int i = 0; i < m; i++)//1번째 사람이 가고싶어하는 편의점
	{
		scanf("%d %d", &y, &x);
		conList.push_back(Cood(x-1, y-1));
	}
	sort(baseList.begin(), baseList.end(), cmp);

	int i = 0;
	while (ans<=m-1)
	{
		for (int j = 0; j < personPos.size(); j++)//1모든 사람이 최단거리로 한칸 움직여야함. n^2*m*while반복
		{
			if(complete[j]==0)
				personPos[j] = findPersonCon(j);
		}
		for (int j = 0; j < personPos.size(); j++)//2.만약 편의점에 도착하면 해당 편의점에ㅓㅅ 멈추고 그칸은 못지나감 움직여야함.
		{
			if (personPos[j].x == conList[j].x && personPos[j].y == conList[j].y&&complete[j]==0)
			{
				arr[personPos[j].y][personPos[j].x] = 2;
				complete[j] = 1;
				ans++;
			}
		}


		if (i < m)//0~m까지 편의점맞는 베이스캠프 정해주기 3번째 n^4*m
		{
			int now = findBase(i);
			personPos.push_back(Cood(baseList[now].x, baseList[now].y));//현재 사람 위치저장
			baseList.erase(baseList.begin() + now);
		}

		i++;
	}
	printf("%d", i);
}

//나온 예외 편의점이랑, 베이스캠프가 같으면?

/*
5 3
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 1
2 5
4 2

5 3
0 0 0 0 0
1 0 0 0 1
0 0 0 0 0
0 1 0 0 0
0 0 0 0 1
2 1
2 5
4 2

11 2
0 0 1 0 0 1 1 1 0 0 1
1 1 1 1 1 1 1 0 0 1 1
0 0 0 0 1 0 1 0 1 0 1
1 0 0 0 0 0 0 1 1 1 1
0 1 0 1 1 0 1 1 0 0 1
0 1 0 1 0 1 0 1 0 0 1
0 0 0 1 0 0 1 1 1 1 0
1 1 1 1 0 0 0 1 0 1 0
1 1 1 1 0 1 1 1 1 1 1
1 1 0 0 0 1 1 1 0 0 1
1 1 0 1 1 0 0 1 1 0 1
2 8
1 9

3 4
0 1 1
1 0 1
1 0 0
3 3
1 1
2 2
3 2

*/