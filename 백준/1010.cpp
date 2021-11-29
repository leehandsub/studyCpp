#include <stdio.h>

using namespace std;

long long dp[31][31];

int main(void)
{
    int t;
    int n,m;
    scanf("%d",&t);
    
    dp[0][0] = 1;
    for(int i=1;i<=30;i++) 
    {
        dp[i][0] = 1;
        for(int j=1;j<=30;j++) 
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        printf("%lld\n",dp[m][n]);
    }

}//처음에는 그냥 조합 하려고 햇는데 29!이 longlong을 뛰어넘어서 답을 봤다. 미친 dp사용이다.
