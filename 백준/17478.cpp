/*
문제 : 재귀함수가 뭔가요?
시간 : 15분?
ide 활용 : x
질문 보기 : x
피드백 : 라고 답변하였지를 2번 출력하는게 맘에 안든다.
\"이게 "를 출력하는방법인지 알게 됏다.
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

int n;

void dfs(int index)
{
	string s;
	for (int i = 0; i < index; i++)
	{
		s.append("____");
	}
	cout << s;
	printf("\"재귀함수가 뭔가요?\"\n");
	if (index == n)
	{
		cout << s;
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		cout << s;
		printf("라고 답변하였지.\n");
		return;
	}
	cout << s;
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	cout << s;
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	cout << s;
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	dfs(index + 1);
	cout << s;
	printf("라고 답변하였지.\n");
}

int main(void)
{
	scanf("%d", &n);
	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	dfs(0);
}
