#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long arr[1025][1025];

int main(void)
{
    int n,m;
    long long now;
    int x1,y1;
    int x2,y2;
    
    scanf("%d %d",&n,&m);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%lld",&now);
            arr[i][j]=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]+now;
        }
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%lld\n",arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1]);
    }
        
}
