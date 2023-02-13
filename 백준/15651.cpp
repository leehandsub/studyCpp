/*
문제 : N과 M (3)
시간 : 30분
ide 활용 : x
질문 보기 : o
피드백 : 전혀 감을 못잡아서 n,m 1의 답을 보고 어떻게 돌아가는지 보고
조건을 고쳐서 풀엇다.
dfs를 포문으로 여러번 부를 생각을 전혀 못햇다. 
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

int arr[10];

int a, b;

void dfs(int index) 
{
	if (index == b) 
	{
		for (int i = 0; i < b; i++)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < a; i++)
	{
		arr[index] = i+1;
		dfs(index + 1);
	}
}

int main(void)
{
	scanf("%d %d", &a, &b);
	dfs(0);
}
