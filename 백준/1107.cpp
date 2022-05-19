#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[10];

int main(void)
{
	int answer;
	int n;
	int now;
	int find = 1;

	scanf("%d", &answer);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &now);
		arr[now] = 1;//1이면 없는거
	}
	now = 999999999;
	now = min(now, abs(100 - answer));

	for (int i = 0; i < 1000001; i++)
	{
		int temp = i;
		if (i == 0)
		{
			if (arr[temp % 10] == 1)
			{
				find = 0;
			}
		}
		while (temp)
		{
			if (arr[temp % 10] == 1)
			{
				find = 0;
				break;
			}
			temp = temp / 10;
		}
		if (find == 1)
		{
			temp = to_string(i).length();
			temp += abs(answer - i);
			now = min(now, temp);
		}
		find = 1;
	}
	printf("%d", now);

}