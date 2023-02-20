/*
문제 : 색종이 만들기
시간 : 40분
ide 활용 : x
질문 보기 : x
피드백 : dfs를 각 사분면을 나누는데 시간이 많이 걸렷다.
처음에는 나누기만 할려고 했지만 다시 첨부터 생각하니
결국에는 현재 index에서 더해주고 빼주고를 해서 풀엇다.
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
int arr[129][129];
int zans = 0;
int oans = 0;

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
		if (arr[istart][jstart] == 0)
			zans++;
		else
			oans++;
		return;
	}
	else//다르다
	{
		dfs(istart, iend - index / 2, jstart, jend - index / 2, index / 2);//1
		dfs(istart, iend - index / 2, jstart + index / 2, jend, index / 2);//2
		dfs(istart + index / 2, iend, jstart, jend - index / 2, index / 2);//3
		dfs(istart + index / 2, iend, jstart + index / 2, jend, index / 2);//4
	}
}

int main(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(1, n, 1, n, n);

	printf("%d\n", zans);
	printf("%d\n", oans);

}
