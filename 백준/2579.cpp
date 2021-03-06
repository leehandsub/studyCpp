/*

문제 : 백준 계단 오르기
시간 : ??(복기)
ide 활용 : 
질문 보기 :

dp사용 2번째 할래 3번째 할래로 경우의 2개로 나눠서 사용

*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[301];
int dp2[301];
int arr[301];
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    dp[1]=arr[1];
    dp[2]=arr[2]+arr[1];
    dp[3]=arr[1]+arr[3];
    dp2[1]=arr[1];
    dp2[2]=arr[2];
    dp2[3]=arr[2]+arr[3];
    for(int i=4;i<=n;i++)
    {
        dp[i]=arr[i]+max(dp[i-2],dp[i-3]+arr[i-1]);
        dp2[i]=arr[i]+max(dp2[i-2],dp2[i-3]+arr[i-1]);
    }
    
    printf("%d\n",max(dp[n],dp2[n]));
}   
