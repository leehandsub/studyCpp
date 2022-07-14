/*
문제 : 백준 카잉 달력
시간 : 25분
ide 활용 : x
질문 보기 : x
피드백 : 최소공배수를 구해서 최대를 잡아놓고
두 숫자를 비교하면서 같아지면 print아니면 작은 것을 커지게 해서 풀었다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main(void)
{
	int t;
	int n, m;
	int x, y;
	
	scanf("%d", &t);
	while (t--)
	{
		int num = 0;
		int nx = 0, ny = 0;
		int i = 0;
		int j = 0;
		scanf("%d %d", &n, &m);
		scanf("%d %d", &x, &y);

		num = n * m / gcd(n, m);//최소공배수

		while (1)
		{
			nx = x + i * n;
			ny = y + j * m;
			if (nx > num || ny > num)
			{
				printf("-1\n");
				break;
			}
			if (nx == ny)
			{
				printf("%d\n", nx);
				break;
			}
			else if (nx > ny)
			{
				j++;
			}
			else
			{
				i++;
			}
		}
	}

}