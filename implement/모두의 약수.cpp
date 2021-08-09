#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int cnt[50001] = { 0 };
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j = j + i) {
			cnt[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d ", cnt[i]);
	}

}
//배수로 직접 배열에 넣어야한다.... 
