/*
문제 : 결혼식
시간 : 20분
ide 활용 : o
질문 보기 : x
피드백 : 그냥 bfs로 풀엇다. 

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

int main(void)
{
	int n;
	int m;

	cin >> n >> m;
	vector<vector<int>> arr(n + 1, vector<int>());
	vector<int> vit(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	queue<pair<int, int>> q;

	q.push({ 1,0 });
	vit[1] = 1;
	int cnt = 0;
	while (!q.empty())
	{
		int now = q.front().first;
		int num = q.front().second;
		q.pop();
		if (num == 2)
			break;
		for (int i = 0; i < arr[now].size(); i++)
		{
			if (vit[arr[now][i]] == 1)
				continue;
			q.push({ arr[now][i],num + 1 });
			vit[arr[now][i]] = 1;
			cnt++;
		}
	}
	cout << cnt;
	
}
  
