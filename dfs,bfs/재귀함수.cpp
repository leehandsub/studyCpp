#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

void DFS(int x) {
	if (x == 0) return;
	else {
		DFS(x - 1);
		printf("%d ", x);
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	DFS(n);

}
