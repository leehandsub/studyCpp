/*
문제 : swea 새로운 불면증 치료법
시간 : 20분
ide 활용 : o
질문 보기 : x
피드백 : 그냥 단순한 구현이다. 몇번째인지 출력하는 줄 알았는데 그 당시 숫자를
출력하는 거라 시간이 조금 걸렷다. 문제를 잘 읽어보자.
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
	int n;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		string arr = "0000000000";
		int i = 1;
		while (1)
		{
			string temp = to_string(n * i);
			for (int j = 0; j < temp.size(); j++)
			{
				arr[temp[j] - '0'] = '1';
			}
			if (arr == "1111111111")
				break;
			i++;
		}
		printf("#%d %d\n", t, n*i);
	}
	
}