#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef struct per
{
	int num;
	int cnt=0;
}per;

int main(void)
{
	int N,M;
	per num[1001];
	int pe[1001];
	int flag = 1;
	int gr[10001];
	int sum = 1;
	int max = -999999;
	int now=0;
	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; j<i; j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)//소수일때
		{
			num[now].num = i;
			now++;
		}
		else
		{
			flag = 1;
		}
	}
	now = 0;
	for (int i = 2; i <= N; i++)
	{
		sum *= i;
		int temp = i;
		while (1)
		{
			if (temp % num[now].num==0)
			{
				num[now].cnt++;
				temp /= num[now].num;
			}
			else if(temp==1)
			{
				break;
			}
			else
			{
				now++;
			}
		}
		now = 0;
	}
	printf("%d! = ", N);
	for (int i = 0; i < N; i++)
	{
		if (num[i].cnt == 0)
			break;
		printf("%d ", num[i].cnt);
	}
}//매번 소인수 분해를 한다 (넘어렵게 풀엇나?)
/*
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, i, j, tmp;
	scanf("%d", &n);
	vector<int> ch(n+1);
	for(i=2; i<=n; i++){
		tmp=i;
		j=2;
		while(1){
			if(tmp%j==0){
				ch[j]++;
				tmp=tmp/j;
			}
			else j++;
			if(tmp==1) break;
		}
	}
	printf("%d! = ", n);
	for(j=2; j<=n; j++){
		if(ch[j]!=0) printf("%d ", ch[j]);
	}
	return 0;
}
*/
