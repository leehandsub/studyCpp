/*
문제 : 회문2
시간 : 1시간
ide 활용 : x
질문 보기 : o
피드백 : 처음에는 시간초과 때문에 억지로 답만 맞추게 25?인가까지만 줫다.
다른 분 피드백을 받아서 답을 받으면 바로 리턴하게 해서 최대한 for문을 안돌게 했다.
귀찬다고 함수만들지 않고 풀면 안되겟다.... 
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

int colCircular(vector<string> arr, int n) {
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int flag = 1;
			if (i + n > 100)
				break;
			for (int l = 0; l < n / 2; l++)
			{
				if (arr[i + l][j] != arr[i + n - l - 1][j])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return n;
		}
	}

	return 0;
}
int rowCircular(vector<string> arr, int n) {
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int flag = 1;
			if (j + n > 100)
				break;
			for (int l = 0; l < n / 2; l++)
			{
				if (arr[i][j + l] != arr[i][j + n - l - 1])
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1)
				return n;
		}
	}

	return 0;
}

int main(void)
{
	int test_case;
	int t;
	int T;
	string s;
	//freopen("input.txt", "r", stdin);
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		vector<string> arr;
		int ans = 1;
		cin >> t;
		for (int i = 0; i < 100; i++)
		{
			cin >> s;
			arr.push_back(s);
		}
		for (int k = 1; k < 100; k++) {
			ans = max(ans, colCircular(arr, k));
		}
		for (int k = ans; k < 100; k++) {
			ans = max(ans, rowCircular(arr, k));
		}

		printf("#%d %d\n", test_case, ans);
	}
}
