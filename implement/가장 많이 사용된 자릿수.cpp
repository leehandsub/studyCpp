#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int cnt[10] = { 0 };
	int N;
	int dig = 10;
	int max = 0;
	int res = 0;
	scanf("%d", &N);
	while (N != 0)
	{
		cnt[N % 10]++;
		N /= 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (max <= cnt[i])
		{
			max = cnt[i];
			res = i;
		}

	}
	printf("%d",res);
}// 답은 문자열을 사용햇는데 숫자가 너무 컷을때를 생각을 안했다...
