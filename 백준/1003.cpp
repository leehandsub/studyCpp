#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[42];//0
int dp2[42];//1

int main(void)
{
    int n,m;
    
    dp[0]=1;
    dp[1]=0;
    dp2[0]=0;
    dp2[1]=1;
    for(int i=2;i<42;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
        dp2[i]=dp2[i-1]+dp2[i-2];
    }
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        printf("%d %d\n",dp[m],dp2[m]);
    }

}
