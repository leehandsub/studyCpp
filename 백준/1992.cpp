/*
문제 : 쿼드트리
시간 : 5분
ide 활용 : x
질문 보기 : x
피드백 : 2630을 풀고나서 바로 푸는데 거의 비슷한 문제라 빨리 풀었다.

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

int n;
vector<string> arr;

void dfs(int istart, int iend, int jstart, int jend, int index)
{
	if (istart > iend || jstart > jend)
		return;
	int flag = 0;
	for (int i = istart; i <= iend; i++)
	{
		for (int j = jstart; j <= jend; j++)
		{
			if (arr[istart][jstart] != arr[i][j])
				flag = 1;
		}
	}

	if (flag == 0)
	{

		if (arr[istart][jstart] == '0')
			printf("0");
		else
			printf("1");
		return;
	}
	else//다르다
	{
		printf("(");
		dfs(istart, iend - index / 2, jstart, jend - index / 2, index / 2);//1
		dfs(istart, iend - index / 2, jstart + index / 2, jend, index / 2);//2
		dfs(istart + index / 2, iend, jstart, jend - index / 2, index / 2);//3
		dfs(istart + index / 2, iend, jstart + index / 2, jend, index / 2);//4
		printf(")");
	}

}

int main(void)
{
	scanf("%d", &n);
	string s;
	for (int i = 1; i <= n; i++)
	{
		s.push_back(' ');
	}
	arr.push_back(s);

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		s = " " + s;
		arr.push_back(s);
	}
	dfs(1, n, 1, n, n);

}
