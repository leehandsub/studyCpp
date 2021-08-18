#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	int cnt = 0;
	int left = 1;
	int cen = 0;
	int right = 1;
	int max = 0;
	int now= 1;
	scanf("%d", &N);

	/*for (int i = 1; i <= N; i++)
	{
		int temp = i;
		while (1)
		{
			if (temp == 3)
			{
				cnt++;
				break;
			}
			if (temp / 10 == 0)
			{
				break;
			}
			if (temp % 10 == 3)
			{
				cnt++;
			}
			temp /= 10;
			
		}
	}*/
	
	while (left != 0)
	{
		left = N /(now*10);
		cen = (N /now)%10;
		right = N % now;

		if (cen > 3)
		{
			cnt += (left+1)*now;
		}
		else if (cen < 3)
		{
			cnt += left*now;
		}
		else
		{
			cnt += (left * now + right + 1);
		}
		now *= 10;
	}

	printf("%d", cnt);

}
