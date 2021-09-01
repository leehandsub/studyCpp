#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	char a[31];
	stack<char> b;

	scanf("%s", a);
	
	for (int i = 0; a[i] != '\0'; i++)
	{
		if (a[i] == '(')
		{
			b.push(a[i]);
		}
		else
		{
			if (b.empty() || b.top() != '(') {
				printf("NO");
				return 0;
			}
			b.pop();
		}
	}
	if (b.empty())printf("YES");
	else printf("NO");
}
