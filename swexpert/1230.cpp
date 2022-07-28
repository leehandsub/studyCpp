/*
문제 : swea 암호문3
시간 : 60분
ide 활용 : o
질문 보기 : o
피드백 : 링크드 리스트 강의 문제라서 처음으로 리스트 stl을 써봣다.
다 빨리 햇는데 \n이나 뛰어쓰기가 계쏙 들어와서 문제가 오래 걸렸다. %c앞에 뛰어쓰기를 넣어서 해결했다...

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
	int n,m;
	int num;
	char c;
	int x, y, s;
	freopen("input.txt", "r", stdin);


	for (int t = 1; t <= 10; t++)
	{
		list<int> arr;
		scanf("%d", & n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			arr.push_back(num);
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf(" %c", &c);
			if (c == 'I')
			{
				list<int> temp;
				scanf("%d %d", &x, &y);
				if (arr.size() < x)
					continue;
				auto iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				for (int j = 0; j < y; j++)
				{
					scanf("%d", &s);
					temp.push_back(s);
				}
				arr.splice(iter, temp);
				
			}
			else if (c == 'D')
			{
				scanf("%d %d", &x, &y);
				if (arr.size() < x)
					continue;
				auto iter = arr.begin();
				for (int j = 0; j < x; j++)
					iter++;
				for (int j = 0; j < y; j++)
					iter=arr.erase(iter);
			}
			else if (c == 'A')
			{
				scanf("%d", &x);
				for (int j = 0; j < x; j++)
				{
					scanf("%d", &s);
					arr.push_back(s);
				}
			}
			else
				continue;

		}

		printf("#%d ", t);
		auto iter = arr.begin();
		for (int i=0;i<10; i++)
		{
			printf("%d ", *iter);
			iter++;
		}
		printf("\n");

	}
	
}