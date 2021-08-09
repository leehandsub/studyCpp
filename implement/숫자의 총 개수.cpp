#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	int sum = 0;
	int dis = 1;
	int big = 10;
	for (int i = 1; i <= N; i++)
	{
		if (i == big)
		{
			dis++;
			big *= 10;
		}
		sum += dis;
	}
	printf("%d", sum);

}//난 결국 한바퀴를 숫자만큼 다 돌지만 답은 몇번 더하기만 해주면 끝이라 시간이 훨씬 줄어든다.
/*
#include<stdio.h>
int main(){
	freopen("input.txt", "rt", stdin);
	int n, sum=0, cnt=1, digit=9, res=0;
	scanf("%d", &n);
	while(sum+digit<n){	
		sum=sum+digit;
		res=res+(cnt*digit);
		cnt++;
		digit=digit*10;
	}
	res=res+((n-sum)*cnt);
	printf("%d\n", res);
	return 0;
}*/
