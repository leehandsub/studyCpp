/*
문제 : 소문난 칠공주
시간 : 2~3시간?
ide 활용 : o
질문 보기 : o
피드백 : 먼저 모든 조합을 뽑아서 bfs로 연결 되있는지 확인한 후 
이다솜파인지 확인 했다.
조합을 뽑는 경우는 검색으로 확인했고 index정리를 잘 못해서 많이 방황했다.
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

vector<string> arr;

vector<int> temp;
vector<int> vit;

int bfsVit[6][6];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main(void)
{
	int ans = 0;
	for (int i = 0; i < 5; i++)
	{
		string now;
		cin >> now;
		arr.push_back(now);
	}
	for (int i = 0; i < 25; i++)
	{
		temp.push_back(i);
		vit.push_back(0);
	}
	for (int i = 0; i < 7; i++)
	{
		vit[i] = 1;
	}

	do {
		set<int> adj;
		int cnt = 0;
		for (int i = 0; i < temp.size(); ++i) {
			if (vit[i])
			{
				adj.insert(temp[i]);
			}
		}
		queue<pair<int,int>> q;
		bfsVit[(*adj.begin())/5][(*adj.begin()) % 5] = 1;
		q.push(make_pair((*adj.begin()) / 5, (*adj.begin()) % 5));
		while (!q.empty()) {
			if (cnt == 7)
				break;
			int x = q.front().second;
			int y = q.front().first;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0||nx>=5||ny<0||ny>=5||bfsVit[ny][nx]==1)
					continue;
				if (adj.find(ny*5+nx)==adj.end())
				{
					continue;
				}
				bfsVit[ny][nx] = 1;
				cnt++;
				q.push(make_pair(ny,nx));
			}
		}
		auto iter = adj.begin();
		for (int i = 0; i < 7; i++)
		{
			bfsVit[(*iter) / 5][(*iter++) % 5] = 0;
		}
		iter = adj.begin();
		if (cnt == 6)
		{
			//성공
			int lee = 0;
			for (int i = 0; i < 7; i++)
			{
				if (arr[*(iter) / 5][*(iter) % 5] == 'S')
					lee++;
				iter++;
				if (lee >= 4)
				{
					ans++;
					break;
				}
			}
		}

	} while (prev_permutation(vit.begin(), vit.end()));

	printf("%d", ans);

	//r 가로 c 세로 
}//조합으로 푼다. 1~2 25 C 7을 구하고 근접한지 -> 임도연파인지 확인
