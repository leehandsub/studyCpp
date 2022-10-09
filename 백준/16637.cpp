/*
문제 : 괄호 추가하기
시간 : 40분
ide 활용 : o
질문 보기 : o
피드백 : 완탐 마스터를 위한 첫걸음이다.
일단 접근을 어떻게 해야할지 몰라서 풀이보고 내 맘대로 짯다.
괄호를 넣을 수 있으면 넣고 나머지를 구하게 구현했다.
나중에 다시 풀면 풀 수 있을려나... 쨋든 괄호 넣을지말지를 idx로 계속 판단하면서 진행하면 된다.
#include <climits>  max_ans = INT_MIN; 요것도 처음 써봤다.
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
#include <climits>

using namespace std;

int n;
string num;
int max_ans;

int cal(int a, int b, char c)
{
	int x;
	if (c == '+')
		x = a + b;
	else if (c == '-')
		x = a - b;
	if (c == '*')
		x = a * b;
	return x;
}


void dfs(int idx, int now)
{
	int a, b;
	char c;
	char nowC;

	if (idx >= n)
	{
		max_ans = max(max_ans, now);
		return;
	}

	if (idx == 0)
		nowC = '+';
	else
		nowC = num[idx - 1];

	a = num[idx]-'0';


	if (idx + 2 < n)
	{
		c = num[idx + 1];
		b = num[idx + 2] - '0';
		int cur = cal(a, b, c);
		dfs(idx + 4, cal(now,cur,nowC));
	}
	dfs(idx + 2, cal(now, a, nowC));
}

int main(void)
{

	scanf("%d", &n);
	cin >> num;
	max_ans = INT_MIN;

	dfs(0,0);

	printf("%d", max_ans);
	
}