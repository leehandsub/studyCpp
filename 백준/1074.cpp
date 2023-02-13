/*
문제 : z
시간 : 50분
ide 활용 : x
질문 보기 : o
피드백 : 어떻게 풀어야하는지 정도 보고 문제를 풀엇다.
먼저 제일 작은 4칸까지 앞에 숫자를 최대한 구한뒤 제일 작은 4칸
에 따라 마지막 숫자를 더해주면 된다.
오래걸린 이유는 a,b좌표도 옮겨야하는 것을 깜빡했따.

*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<math.h>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

int main(void)
{
	int n, a, b;
	int ans = 0;

	scanf("%d %d %d", &n, &a, &b);


	while (n != 1)
	{
		int num = pow(2, --n);//2
		if (a < num && b < num)
		{
			ans += 0;
		}
		else if (a < num && b >= num)
		{
			b -= num;
			ans += num * num;
		}
		else if (a >= num && b < num)
		{
			a -= num;
			ans += 2 * num * num;
		}
		else
		{
			a -= num;
			b -= num;
			ans += 3 * num * num;
		}
	}
	a++;
	b++;
	if (a < 2 && b < 2)
		ans += 0;
	else if (a < 2 && b >= 2)
		ans += 1;
	else if (a >= 2 && b < 2)
		ans += 2;
	else
		ans += 3;

	printf("%d",ans);
}
