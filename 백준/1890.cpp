#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int vit[101][101];
long long dp[101][101];
int main(void) {
	
	int n;
	int now=0;
	queue<pair<int,int>> q;
	int i=0,j=0;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	        cin>>arr[i][j];
	}
	
	dp[0][0]=1;
	
	for(int i=0;i<n;i++)
	{
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
                continue;
            if(i+arr[i][j]<n)
                dp[i+arr[i][j]][j]+=dp[i][j];
            if(j+arr[i][j]<n)
                dp[i][j+arr[i][j]]+=dp[i][j];    
        }
	}
	/*vit[0][0]=1;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
	    i=q.front().first;
	    j=q.front().second;
	    q.pop();
	    if(arr[i][j]==0||vit[i][j]==1)
	        continue;
	    vit[i][j]=1;
	    if(i+arr[i][j]<n)
	    {
    	    if(i+arr[i][j]!=n-1||j!=n-1)
    	        q.push(make_pair(i+arr[i][j],j));
    	    dp[i+arr[i][j]][j]+=dp[i][j];
	    }
	    if(j+arr[i][j]<n)
	    {
    	    if(i!=n-1||j+arr[i][j]!=n-1)
    	        q.push(make_pair(i,j+arr[i][j]));
    	    dp[i][j+arr[i][j]]+=dp[i][j];
	    }
	    
	}처음에는 dp+bfs로 빠르게 해볼라 햇는데 생각보다 겹치는게 많이 나와서 좀만 들가도 메모리 초과낫다... 그래서 그냥 단순하게 생각해서 풀었다.*/
	printf("%lld",dp[n-1][n-1]);
}
