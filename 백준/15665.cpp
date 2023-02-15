15665/*
문제 : N과 M (11)
시간 : 30분
ide 활용 : x
질문 보기 : x
피드백 : n과 m (3)을 이용해서 풀엇다.
주는 배열의 중복을 제거하고 depth마다 새로운 값을 줫다.

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

vector<int> arr;
int temp[10];
int a, b;
int n;

void dfs(int size) 
{
	if (size == b)
	{
		for (int i = 0; i < b; i++)
		{
			printf("%d ", temp[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		temp[size] = arr[i];
		dfs(size+1);
	}
}

int main(void)
{
	scanf("%d %d", &a, &b);
	int now;
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &now);
		arr.push_back(now);
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	dfs(0);

	//r 가로 c 세로 
}
