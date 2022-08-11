/*
문제 : swea 염라대왕의 이름 정렬
시간 : 15분
ide 활용 : x
질문 보기 : o
피드백 : cmp쓰는 방법을 까먹어서 찾아봤다. 
중복제거를 하기위해서는 먼저 정렬부터하고 중복제거를 해야한다.
strcpy(temp, arr[i].c_str()); string to char
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(string A, string B) {
	if (A.size() == B.size())
		return A < B;
	return A.size() < B.size();
}

int main(void)
{
	int T;
	int n;
	int num;
	char c;
	int x, y;
	char s[51];
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		vector<string> arr;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", s);
			arr.push_back(s);
		}
		sort(arr.begin(), arr.end(), cmp);
		arr.erase(unique(arr.begin(), arr.end()), arr.end());

		printf("#%d\n", t);
		for (int i = 0; i < arr.size(); i++)
		{	
			char temp[51];
			strcpy(temp, arr[i].c_str());
			printf("%s\n", temp);
		}
	}
}