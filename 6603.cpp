/*
문제 : 로또
시간 : 15분?
ide 활용 : x
질문 보기 : x
피드백 : 기본적인 조합 문제이다.
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

	while (1)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			break;
		vector<int> arr;
		vector<int> vit;
		int num;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &num);
			arr.push_back(num);
			if (i >= 6)
				vit.push_back(0);
			else
				vit.push_back(1);
		}

		do {
			for (int i = 0; i < n; i++)
			{
				if (vit[i] == 1)
				{
					printf("%d ", arr[i]);
				}
			}
			printf("\n");
		} while (prev_permutation(vit.begin(), vit.end()));
		printf("\n");
	}

}
