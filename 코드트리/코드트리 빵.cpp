/*
���� : �ڵ�Ʈ�� ��
�ð� : 2�ð�30��
ide Ȱ�� : o
���� ���� : o
�ǵ�� : �ܼ� ���� �����̴�.
���ܷ� ó�� ���̽�ķ���� ���ϴµ� �Ÿ��� ª�� ������ ��찡 �ִ�.(2�� �ѷ�����)
�̷��� ���ѷ��� ���Ƽ� �ð��ʰ��� �ߴµ� �׷��� �����ϸ� ���� ������� �����ߴ�.��������
�ܼ������ϸ鼭 �����ϴ� ���� 2�� �������� ���� �ִ� ���ܻ�Ȳ�� �־���.(�̰� ������ ã�Ѵ�.)

!!	1.������ Ǯ�� ���� ���ɿ� ���� �׸��� �׸���
	2.input�� �ߺ����Ѵ�. �̹����� x,y�� �ݴ�� ���� 2,2�� 1,1�κ�ȯ�� ����...
	3.�ð��ʰ� �ȵ��� ������ �ð��ʰ��� �� ���ѹݺ��� �ǽ�����
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

int dx[4] = { 0,-1,1,0 };//�ϼ�����
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

	for (int i = 0; i < baseList.size(); i++)//0��° �༮ ���̽�ķ�� ã�� n^4
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

	arr[baseList[idx].y][baseList[idx].x] = 2;//�� ����
	

	return idx;
}


Cood findPersonCon(int personIndex)//������ġ�� ���� �Ųٷ� bfs����.
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

	for (int i = 0; i < m; i++)//1��° ����� ����;��ϴ� ������
	{
		scanf("%d %d", &y, &x);
		conList.push_back(Cood(x-1, y-1));
	}
	sort(baseList.begin(), baseList.end(), cmp);

	int i = 0;
	while (ans<=m-1)
	{
		for (int j = 0; j < personPos.size(); j++)//1��� ����� �ִܰŸ��� ��ĭ ����������. n^2*m*while�ݺ�
		{
			if(complete[j]==0)
				personPos[j] = findPersonCon(j);
		}
		for (int j = 0; j < personPos.size(); j++)//2.���� �������� �����ϸ� �ش� ���������ä� ���߰� ��ĭ�� �������� ����������.
		{
			if (personPos[j].x == conList[j].x && personPos[j].y == conList[j].y&&complete[j]==0)
			{
				arr[personPos[j].y][personPos[j].x] = 2;
				complete[j] = 1;
				ans++;
			}
		}


		if (i < m)//0~m���� �������´� ���̽�ķ�� �����ֱ� 3��° n^4*m
		{
			int now = findBase(i);
			personPos.push_back(Cood(baseList[now].x, baseList[now].y));//���� ��� ��ġ����
			baseList.erase(baseList.begin() + now);
		}

		i++;
	}
	printf("%d", i);
}

//���� ���� �������̶�, ���̽�ķ���� ������?

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