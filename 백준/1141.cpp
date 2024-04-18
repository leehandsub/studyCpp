/*
문제 :접두사
시간 :40분
ide 활용 : o
질문 보기 : o
피드백 : 음... 문제 이해는 갓는데 어떻게 풀어야할지 고민을 좀 햇다.고민을 해도 잘 모르겠어서
답을 봣는데 정렬하고 지금 현재 문자열과 밑에 모든 문자열을 비교해서 접두사있으면 빼면 된다.
음... 그냥 코테에서 나오면 어떻게 풀지 고민 오래 햇을거 같다....
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

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	string s;
	cin >> n;

	vector<string> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr.push_back(s);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j].substr(0, arr[i].size()) == arr[i])
			{
				n--;
				break;
			}
		}
	}

	cout << n;
}
