/*
문제 : swea 중위순회
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 딴거보다 scanf로 받는 것중 필요없다고 생각하는게 있어서 문제가 있었다. 
결국 if문으로 경우마다 줬다...

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

char arr[101];
int n, m, l;

void inorder(int i)
{
	if (i > n)
		return;
	inorder(2 * i);
	printf("%c", arr[i]);
	inorder(2 * i + 1);
}

int main(void)
{
	int T;

	int num;
	char c;
	int x, y;
	freopen("input.txt", "r", stdin);
	//scanf("%d", &T);

	for (int t = 1; t <= 10 ; t++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d %c", &num, &c);
			arr[i] = c;
			if (num * 2 < n)
				scanf("%d %d", &x, &y);
			else if (num * 2 == n)
				scanf("%d", &x);
		}
		printf("#%d ", t);
		inorder(1);
		printf("\n");	
	}
}