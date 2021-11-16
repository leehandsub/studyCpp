
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[11];

int main(void)
{
    int n,m;
    
    scanf("%d",&n);
    
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    for(int i=4;i<11;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    
    for(int j=0;j<n;j++)
    {
        scanf("%d",&m);
        printf("%d\n",dp[m]);
    }
}
