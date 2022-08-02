/*
문제 : swea 수열 편집
시간 : 30분
ide 활용 : o
질문 보기 : x
피드백 : 그냥 링크드 리스트 문제 링크드 리스트를 내가 직접 짜면 더 빠를거 같긴한데
일단 stl을 사용했다.
iter을 erase하면 다시 줘야하는 것을 처음 깨달았다.

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
	int n,m,l;
	int num;
	char c;
	int x, y;
	
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		
		scanf("%d %d %d", &n, &m, &l);
		list<int> arr;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			arr.push_back(num);
		}
		for (int i = 0; i < m; i++)
		{
			scanf(" %c", &c);
			if (c == 'I')
			{
				scanf("%d %d", &x, &y);
				auto iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				arr.insert((iter), y);
			}
			else if (c == 'D')
			{
				scanf("%d", &x);
				auto iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				arr.erase(iter);
			}
			else if (c == 'C')
			{
				scanf("%d %d", &x, &y);
				auto iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				arr.erase(iter);
				iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				arr.insert((iter), y);
			}
			else
				continue;
		}
		if (arr.size() < l)
			printf("#%d -1\n",t);
		else
		{
			auto iter = arr.begin();
			for (int j = 0; j < l; j++)
				iter++;
			printf("#%d %d\n", t, *iter);
		}
		
	}
}