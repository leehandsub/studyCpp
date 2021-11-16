#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001];

int main(void)
{
    int n,m;
    
    scanf("%d",&n);
    
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
    {
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }

    printf("%d",dp[n]);
}
