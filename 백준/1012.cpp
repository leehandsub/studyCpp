#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int arr[51][51];

int main(void)
{
    int n,m,k;
    int x,y;
    int cnt=0;
    int t;
    queue<pair<int,int>> q;
    scanf("%d",&t);
    
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=0;i<k;i++)
        {
            scanf("%d %d",&x,&y);
            arr[x][y]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]==1)
                {
                    cnt++;
                    q.push(make_pair(i,j));
                    arr[i][j]=0;
                    while(!q.empty())
                    {
                        x=q.front().first;
                        y=q.front().second;
                        q.pop();
                        for(k=0;k<4;k++)
                        {
                            if(x+dx[k]<0||x+dx[k]>=n||y+dy[k]<0||y+dy[k]>=m||arr[x+dx[k]][y+dy[k]]==0)
                                continue;
                            q.push(make_pair(x+dx[k],y+dy[k]));
                            arr[x+dx[k]][y+dy[k]]=0;
                        }
                    }
                }
            }
        }
        printf("%d\n",cnt);
        cnt=0;
        
    }


}
