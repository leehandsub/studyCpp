#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	vector<char> c;
	int now;
	stack<int> b;
	scanf("%d",&N);
	int i=1;
	int j = 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &now);
		b.push(now);
		c.push_back('P');
		while (1)
		{
			if (b.empty())break;
			if (j == b.top())
			{
				b.pop();
				j++;
				c.push_back('O');
			}
			else break;
		}
	}
	if (!b.empty())printf("impossible");
	else
	{
		for (i = 0; i < c.size(); i++)
		{
			printf("%c", c[i]);
		}
	}
}
