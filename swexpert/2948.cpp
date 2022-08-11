/*
문제 : swea 문자열 교집합
시간 : 10분
ide 활용 : o
질문 보기 : x
피드백 : 그냥 hash를 간단히 사용했다. find,count둘다 써도 되는데
count로 풀었다. a,b둘다 사용해야하는데 a만사용해서 띠용하다가 패스

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

int main(void)
{
	int T;
	int n;
	int num;
	int a, b;
	int k;
	string s;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d", &a, &b);
		unordered_map<string, int> arr;
		int ans = 0;

		for (int i = 0; i < a; i++)
		{
			cin >> s;
			arr.insert(make_pair(s, 1));
		}
		for (int i = 0; i < b; i++)
		{
			cin >> s;
			if (arr.count(s) == 1)
			{
				ans++;
			}
		}
		printf("#%d %d\n", t, ans);

	}
}