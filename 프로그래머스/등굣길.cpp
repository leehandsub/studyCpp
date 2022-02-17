#include <string>
#include <vector>

using namespace std;

int dp[101];
int arr[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0;i<puddles.size();i++)
    {
        if(m==1||n==1)
        {
            if(puddles[i][1]==m)
                return 0;
            if(puddles[i][0]==n)
                return 0;
        }
        arr[puddles[i][1]-1][puddles[i][0]-1]=-1;
    }
    for(int i=0;i<m;i++)
    {
        if(arr[0][i]==-1)
            break;
        arr[0][i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i][0]==-1)
            break;
        arr[i][0]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(arr[i][j]==-1)
            {
                printf("%d ",arr[i][j]);
                continue;
            }
            if(arr[i-1][j]==-1)
                arr[i][j]=arr[i][j-1];
            else if(arr[i][j-1]==-1)
                arr[i][j]=arr[i-1][j];
            else if(arr[i-1][j]==-1&&arr[i][j-1]==-1)
                arr[i][j]=0;
            else
                arr[i][j]=(arr[i-1][j]+arr[i][j-1])%1000000007;
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    answer=arr[n-1][m-1];
    return answer;
}
