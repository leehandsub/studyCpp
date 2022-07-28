/*
문제 : swea 이진수 표현
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 비트 연산자 맛보기를 해봣다.
m=m>>1해야하는데 m>>1만해서 오래 걸렷다....
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
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void)
{
	int T;
	int n,m;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf("%d %d", &n,&m);
		int i;
		for (i = 0; i < n; i++)
		{
			if ((m & 1 )!= 1)
			{
				printf("#%d OFF\n",t);
				break;
			}
			m= m >> 1;
		}
		if (i == n)
			printf("#%d ON\n", t);

	}
	
}