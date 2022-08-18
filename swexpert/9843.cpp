/*
문제 : swea 촛불 이벤트
시간 : 40분
ide 활용 : x
질문 보기 : o
피드백 : 등차수열이라 n(n+1)/2을 이용했다.
n<sqrt(2*k)이므로 sqrt(2*k)구해 소수점 버림을 하고 n(n+1)/2==k인지 확인했다.
visual에서는 math.h를 안해도 됐는데 swea에서 자꾸 실행이안돼 고민하다 헤더를 추가하니 됐다.
cin을 첨에 사용하다 scanf를하니 시간초과가 안떳다. 한 20분은 삽질한거 같다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<long long> arr;

int main(void)
{
	int T;
	int num;
	char c;
	int x, y;
	//int n,p;
	long long n;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		scanf("%lld", &n);

		long long a = sqrt(n * 2);

		if (a * (a + 1) / 2 == n)
			printf("#%d %d\n", t, a);
		else
			printf("#%d %d\n", t, -1);
	}
}