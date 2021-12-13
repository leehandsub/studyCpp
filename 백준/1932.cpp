#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[501][501];
int arr[501][501];

int main(void)
{
    int n,m;
    int ma=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    dp[0][0]=arr[0][0];
    dp[1][0]=dp[0][0]+arr[1][0];
    dp[1][1]=dp[0][0]+arr[1][1];
    for(int i=2;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j]+arr[i][j];
            }
            else if(j==i)
            {
                dp[i][j]=dp[i-1][j-1]+arr[i][j];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+arr[i][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ma<dp[n-1][i])
        {
            ma=dp[n-1][i];
        }
    }
    printf("%d",ma);
}
