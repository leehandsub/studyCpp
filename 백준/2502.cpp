/*
문제 :떡 먹는 호랑이
시간 :20분
ide 활용 : x
질문 보기 : x
피드백 : 완탐문제이다. d에서 d-1까지 모든 경우의 수를 확인하면서 조건에 맞으면 출력하게 햇다.
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
#include <stack>
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

int d, k;
vector<int> arr(40);

bool dfs(int now)
{
	if (now == 2)
		return true;

	arr[now - 2] = arr[now] - arr[now - 1];
	if (arr[now - 2] <= 0||arr[now-2]>=arr[now-1])
		return false;

	return dfs(now - 1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> d >> k;
	arr[d] = k;
	for (int i = k-1; i > 0; i--)
	{
		arr[d - 1] = i;
		if (dfs(d))
		{
			cout << arr[1] << "\n" << arr[2];
			break;
		}
	}
}
