#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	int two=0;
	int five = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (1)
		{
			if (temp % 2 != 0)
				break;
			else
			{
				two++;
				temp /= 2;
			}
		}
		temp = i;
		while (1)
		{
			if (temp % 5 != 0)
				break;
			else
			{
				five++;
				temp /= 5;
			}
		}
	}
	printf("%d", min(two, five));

}