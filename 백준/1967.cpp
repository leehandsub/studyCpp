/*
문제 : 트리의 지름
시간 : 1시간
ide 활용 : o
질문 보기 : o
피드백 : 어떻게 풀어야하는지 몰라 힌트를 보고 풀엇다.
음... 트리의 특성인지 모르겟지만 검색을하니 먼저 1에서 제일 먼 것을 찾고 거기서 제일 먼곳을 찾으면 답이라고 한다.
재귀 탈출 조건이 인접행렬 size==0일걸로 계속 생각햇는데 생각해보니 1일때 인 것말고는 구현은 잘한 거 같다.
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

vector<vector<pair<int, int>>> arr;

int vit[10001];
int ans = 0;
int m_ans = 0;

void dfs(int start,int sum)
{
	if (arr[start].size() == 1)
	{
		if (m_ans < sum)
		{
			m_ans = sum;
			ans = start;
		}
	}

	for (int i = 0; i < arr[start].size(); i++)
	{
		int now = arr[start][i].first;
		if (vit[now] == 0)
		{
			vit[now] = 1;
			dfs(now,sum+arr[start][i].second);
			vit[now] = 0;
		}

	}
}


int main(void)
{
	int n, k;
	
	cin >> n;
	int a, b, c;

	vector<vector<pair<int, int>>> temp( n+1, vector<pair<int, int>>());
	
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b >> c;
		temp[a].push_back({ b,c });
		temp[b].push_back({ a,c });
	}
	arr = temp;

	vit[1] = 1;
	dfs(1,0);

	vit[1] = 0;
	vit[ans] = 1;

	dfs(ans, 0);

	cout << m_ans;

}
