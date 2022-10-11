/*
문제 : 백준 신기한 소수
시간 : 40분
ide 활용 : x
질문 보기 : x
피드백 : 처음에는 dfs로 풀려다가 아직 익숙치 않아 바로 bfs로 바꿔 풀었다.
bfs로 돌면서 소수가 아니면 push안하고 q에 있는 값의 길이와 n이 같으면 ans배열에 넣어주고 소팅했다.
다른사람의 답을 보니 dfs로는 다음 나올 수를 for문으로 돌면서 현재의 값과 현재 길이를 주면된다. 
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
#include <climits>

using namespace std;

int n;
vector<int> ans;
int arr[5] = { 1,3,5,7,9 };


int findN(int num)
{
	int find = 0;
	while (num)
	{
		num /= 10;
		find++;
	}
	return find;
}
bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void bfs(int num)
{
	queue<int> q;

	q.push(num);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < 5; i++)
		{
			int temp = now * 10 + arr[i];
			if (isPrime(temp))
			{
				if (findN(temp) == n)
				{
					ans.push_back(temp);
					continue;
				}
				q.push(temp);
			}
		}
	}
}

int main(void)
{
	scanf("%d", &n);

	if (n == 1)
	{
		ans.push_back(2);
		ans.push_back(3);
		ans.push_back(5);
		ans.push_back(7);
	}

	bfs(2);
	bfs(3);
	bfs(5);
	bfs(7);

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}

}
