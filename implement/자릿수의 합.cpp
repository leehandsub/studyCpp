#include <stdio.h>
#include <iostream>
using namespace std;

int digit_sum(int n)
{
	int sum = 0;
	int big = 10000000;
	for (int i = 1; i <= 8; i++)
	{
		sum += n / big;
		n = n % big;
		big /= 10;
	}
	return sum;
}

int main(void)
{
	int cnt[64] = { 0 };
	int N, num, max = 0,now=0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		now = digit_sum(num);
		if (cnt[now] != 0&&cnt[now]>num)//여기서 너무 시간 먹엇다
		{
			continue;
		}
		cnt[now] = num;
		if (max < now)
		{
			max = now;
		}

	}
	printf("%d", cnt[max]);
}
//30분 걸림...
/*
#include<stdio.h>
int digit_sum(int x){
	int sum=0, tmp;
	while(x>0){
		tmp=x%10;
		sum=sum+tmp;
		x=x/10;
	}
	return sum;
}

int main(){
	freopen("input.txt", "rt", stdin);
	int n, num, i, sum, max=-2147000000, res;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &num);
		sum=digit_sum(num);
		if(sum>max){
			max=sum;
			res=num;
		}
		else if(sum==max){
			if(num>res) res=num;
		}
	}
	printf("%d\n", res);
	return 0;
}*/
