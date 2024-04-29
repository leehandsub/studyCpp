/*
문제 :감소하는 수
시간 :90분
ide 활용 : o
질문 보기 : o
피드백 : 머리 쓰는 문제가 나오니 역시 너무 약한거 같기도 하고?
처음에 그냥 노가다로 어렵게 풀까 하다가 먼가 쉬운 풀이가 있을거 같아 생각을 좀햇다.
아예 싹 1부터 완탐으로 풀엇는데 물론 시간초과가 일어낫다 그래서 질문도 보고 답도 보면서 생각했다.
98765343210이 마지막 숫자인 것을 알게 됐고 답은 3개 봣는데 3개 풀이가 다 달랏다.
dfs, 약간 dp느낌 나는 풀이, 큐를 이용한 풀이 등 있엇는데 일단 dp느낌 나는대로 풀었다.
먼저 숫자를 넣어두고 그 숫자에 대해 작은 숫자를 계속 넣어주는식으로 풀었다.
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

vector<long long> arr;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i <= 9; i++)
	{
		arr.push_back(i);
	}
	int j = 0;
	while (arr[j]!=9876543210)
	{
		for (int i = 0; i <=9; i++)
		{
			if (arr[j] % 10 > i)
				arr.push_back(arr[j] * 10 + i);
			else 
				break;
		}
		j++;
	}

	if (n >= arr.size())
		cout << -1;
	else
		cout << arr[n];
}
