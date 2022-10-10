/*
문제 : 백준 파이프 옮기기 1
시간 : 50분
ide 활용 : x
질문 보기 : o
피드백 : 처음에는 각각의 경우를 모두 나눠 풀려고 했는데 경우의 수가 너무 많아 머리가 터질뻔했다.
그래서 다른사람의 해설을 보고 dfs나 bfs로 완탐을하면 풀 수 있는 것을 알았다...
완탐으로 생각하니 매우 쉽게 풀렸고 다른 사람은 dp로 풀었다는데 나중에 확인해봐야겠다.
n의 숫자를 잘못읽어 한번 틀렸다. ㅜ
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
#include <climits>

using namespace std;

int arr[20][20];
int ans[20][20];
int n;

bool findRow(int i, int j)
{
	if (j + 1 >= n || arr[i][j + 1] == 1)
		return false;
	return true;
}
bool findCol(int i, int j)
{
	if (i + 1 >= n || arr[i+1][j] == 1)
		return false;
	return true;

}
bool findLine(int i, int j)
{
	if (i + 1 >= n || j + 1 >= n|| arr[i][j + 1] == 1 || arr[i+1][j] == 1 || arr[i+1][j + 1] == 1)
		return false;
	return true;
}

void dfs(int y, int x, int state)
{
	ans[y][x]++;
	if (state == 0)
	{
		if (findRow(y, x))
			dfs(y, x + 1, 0);
		if (findLine(y, x))
			dfs(y + 1, x + 1, 2);
	}
	if (state == 1)
	{
		if (findCol(y, x))
			dfs(y+1, x, 1);
		if (findLine(y, x))
			dfs(y + 1, x + 1, 2);
	}
	if (state == 2)
	{
		if (findRow(y, x))
			dfs(y, x + 1, 0);
		if (findCol(y, x))
			dfs(y + 1, x, 1);
		if (findLine(y, x))
			dfs(y + 1, x + 1, 2);
	}
}

int main(void)
{

	scanf("%d", &n);

	ans[0][1] = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	dfs(0, 1, 0);//0 가로 1 세로 2 대각선

	printf("%d", ans[n - 1][n - 1]);
}