/*
문제 : 작업순서
시간 : 50분?
ide 활용 : x
질문 보기 : x
피드백 :  dfs와  map을 사용해서 풀었다.
먼저 인접리스트로 그래프를 만들고 각 정점에 map을 이용해 선행이 몇개인지 저장시켯다.
선행이 아예 없는 정점부터 시작하여 dfs를 돌며 선행이 1초과하면 그 정점의 map을 -1시켜 다녀왔다는 것을 저장했다.
그래서 선행이 1인 정점을 프린트하여 문제를 풀었다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

map<int, int> m;

void dfs(int v, vector<vector<int>> arr)
{
	if (m[v] > 1)
	{
		m[v] = m[v] - 1;
		return;
	}
	else
	{
		printf("%d ", v);
		for (int i = 0; i < arr[v].size(); i++)
		{
			dfs(arr[v][i], arr);
		}
	}
}

int main(void)
{
	int test_case;
	string s;
	int v, e;
	int a, b;
	freopen("input.txt", "r", stdin);

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> v;
		cin >> e;
		printf("#%d ", test_case);
		vector<vector<int>> arr(v+1);
		for (int i = 0; i < e; i++)
		{
			scanf("%d %d", &a, &b);
			arr[a].push_back(b);
			if (m.count(a) == 0)
				m.insert(make_pair(a, 0));
			if (m.count(b) == 0)
				m.insert(make_pair(b, 0));
			if (m.count(b) == 1)
				m[b] = m[b] + 1;
		}

		for (int i = 1; i <= v; i++)
		{
			if (m[i] == 0)
				dfs(i,arr);
		}
		m.clear();
		printf("\n");
		//cout << ans << "\n";
	}
}
