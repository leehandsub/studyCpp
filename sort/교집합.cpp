#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
void qsort(int* arr, int start, int end) {
	//분할된 원소가 0개이거나 1개 일때까지 함수 호출 
	if (start >= end) {
		return;
	}

	int pivot = start;	//피봇은 첫 번째 원소 
	int i = pivot + 1;	//i는 피봇 다음원소 
	int j = end;	//j는 마지막 원소 
	int temp;

	while (i <= j) {
		//피봇 보다 큰 값 만날 때 까지
		while (i <= end && arr[i] <= arr[pivot]) {
			++i;
		}
		//피봇 보다 작은 값 만날 때 까지
		while (j > start && arr[j] >= arr[pivot]) {
			--j;
		}

		//위에서 계산된 i와 j가 만나거나 엇갈리면 종료
		if (i >= j) break;

		//두 원소 교환 
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	//피봇 정렬 완료 
	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	qsort(arr, start, j - 1);	//피봇 중심으로 왼쪽부분 분할
	qsort(arr, j + 1, end);	//피봇 중심으로 오른쪽부분 분할

}
int main(void)
{
	int a[60001] = { 0 };
	int b[30001] = { 0 };
	int c[60001] = { 0 };
	int N, M;
	int flag;
	int k = 0, j = 0;
	int num;
	scanf("%d", &N);


	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &M);
	for (int i = N; i < N+M; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(a, 0, N + M-1);

	for (int i = 0; i < N + M-1; i++)
	{
		if (a[i] == a[i+1])
		{
			printf("%d ", a[i]);
		}
	}
}
/*
i#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, m, i, p1=0, p2=0, p3=0;
	scanf("%d", &n);
	vector<int> a(n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	
	scanf("%d", &m);
	vector<int> b(m), c(m);
	for(i=0; i<m; i++){
		scanf("%d", &b[i]);
	}
	sort(b.begin(), b.end());
	
	while(p1<n && p2<m){
		if(a[p1]==b[p2]){
			c[p3++]=a[p1++];
			p2++;
		}
		else if(a[p1]<b[p2]){
			p1++;
		}
		else p2++;
	}
	for(i=0; i<p3; i++){
		printf("%d ", c[i]);
	}
	return 0;
}
*/
