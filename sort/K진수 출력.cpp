#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N, M;
	stack<int> a;
	char b[20] = "0123456789ABCDEF";
	scanf("%d %d", &N, &M);
	while (N > 0) {
		a.push(N % M);
		N /= M;
	}
	while (!a.empty()) {
		printf("%c", b[a.top()]);
		a.pop();
	}
}
