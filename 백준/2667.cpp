/*

문제 : 백준 단지번호붙이기
시간 : 20분
ide 활용 : o
질문 보기 : x
피드백 : 오래만에 bfs 구현해서 vit넣는 부분이 어색했다.
다음부터는 nx,ny도 활용 해야겠다.
bfs기초인듯

*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[26][26];
int vit[26][26];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void)
{
	int n;
	int x, y;
	queue<pair<int, int>> q;
	vector<int> answer;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1&&vit[i][j]==0)
			{
				cnt++;
				q.push(make_pair(i, j));
				vit[i][j] = 1;
				while (!q.empty())
				{
					x = q.front().second;
					y = q.front().first;

					q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (x + dx[k] < 0 || x + dx[k] >= n || y + dy[k] < 0 || y + dy[k] >= n || vit[y + dy[k]][x + dx[k]] == 1 || arr[y + dy[k]][x + dx[k]] != 1)
							continue;
						q.push(make_pair(y + dy[k], x + dx[k]));
						vit[y + dy[k]][x + dx[k]] = 1;
						cnt++;
					}
				}
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (int i = 0; i < answer.size(); i++)
	{
		printf("%d\n", answer[i]);
	}

}