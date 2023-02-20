/*
문제 : 암호 만들기
시간 : 20분?
ide 활용 : o
질문 보기 : x
피드백 : 먼저 입력받고 소팅한 한다음에 조합으로 뽑아서 암호을 판단한다.
prev_permutation,next_permutation를 헷갈려서 ide를 사용했다.
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

int pass(vector<char> temp)
{
	int mo = 0;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u')
			mo++;
		if (temp.size() - mo < 2)
			return 0;
	}
	if (mo == 0)
		return 0;
	else
		return 1;
}
int main(void)
{
	int l, c;
	scanf("%d %d", &l, &c);
	vector<char> arr;

	vector<int> vit;

	for (int i = 0; i < c; i++)
	{
		char t;
		scanf(" %c", &t);
		arr.push_back(t);
		vit.push_back(0);
	}
	for (int i = 0; i < l; i++)
	{
		vit[i] = 1;
	}
	sort(arr.begin(), arr.end());
	do {
		vector<char> temp;

		for (int i = 0; i < c; i++)
		{
			if (vit[i] == 1)
				temp.push_back(arr[i]);
		}
		if (pass(temp) == 1)
		{
			for (int i = 0; i < temp.size(); i++)
			{
				printf("%c", temp[i]);
			}
			printf("\n");
		}
	} while (prev_permutation(vit.begin(), vit.end()));

}
