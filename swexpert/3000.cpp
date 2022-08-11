/*
문제 : swea 중간값 구하기
시간 : 40분
ide 활용 : x
질문 보기 : o
피드백 : max,minheap을 사용하면서 사이즈에 따라 중간값을 정해주는 방법으로 풀었다.
heap으로 어떻게 풀지 생각하다 생각이 안나 질문을 봣는데 매우 놀랫다.
구현은 빨리 햇는데 \n을 계속 안넣어줘서 시간이 오래 걸렸다....

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
	int a, b;
	int x, y;

	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		priority_queue<int> maxPq;
		priority_queue<int, vector<int>, greater<int>> minPq ;
		int num=0;
		scanf("%d %d", &n, &a);
		maxPq.push(a);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &a, &b);
			if (maxPq.top() > a)
				maxPq.push(a);
			else
				minPq.push(a);
			if (maxPq.top() > b)
				maxPq.push(b);
			else
				minPq.push(b);
			if (maxPq.size() != minPq.size() + 1)
			{
				if (maxPq.size() > minPq.size())
				{
					minPq.push(maxPq.top());
					maxPq.pop();
				}
				else
				{
					maxPq.push(minPq.top());
					minPq.pop();
				}
			}
			num = (num+maxPq.top()) % 20171109;
		}
		printf("#%d %d\n", t, num);
	}
}