#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main(void)
{
	int N;
	int cnt = 0;
	int cnt2 = 0;
	int max = 0;
	scanf("%d", &N);

	for (int i = 2; i <= N; i++)
	{
		int temp = i;
		while (1)
		{
			if (temp % 2 == 0)
			{
				cnt++;
				temp /= 2;
			}
			else if (temp %5== 0)
			{
				cnt2++;
				temp /= 5;
			}
			else
			{
				break;
			}
		}
	}
	if (cnt > cnt2)
	{
		printf("%d", cnt2);
	}
	else
	{
		printf("%d", cnt);
	}

}
