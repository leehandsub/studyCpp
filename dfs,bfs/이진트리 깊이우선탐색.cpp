#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void pre(int n)//전위
{
	if (n > 7)
		return;
	else
	{
		printf("%d ", n);
		pre(2 * n);
		pre(2 * n + 1);
	}
}

void in(int n)//중위
{
	if (n > 7)
		return;
	else
	{
		in(2 * n);
		printf("%d ", n);
		in(2 * n + 1);
	}
}

void post(int n)//후위
{
	if (n > 7)
		return;
	else
	{
		post(2 * n);
		post(2 * n + 1);
		printf("%d ", n);
	}
}

int main(void)
{
	int N;
	int now;
	pre(1);
	puts("");
	in(1);
	puts("");
	post(1);

}
