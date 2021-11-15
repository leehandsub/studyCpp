#include <iostream>
#include <string>
#include <vector>
#include <queue>

int arr[501][501];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

using namespace std;
int main(void)
{
    int n,m;
    int x,y;
    int cnt=0;//land
    int max=0;//
    int sum=0;
    queue<pair<int,int>> q;
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }   
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
                    sum++;
                    for(int k=0;k<4;k++)
                    {
                        if(x+dx[k]<0||x+dx[k]>=n||y+dy[k]<0||y+dy[k]>=m||arr[x+dx[k]][y+dy[k]]==0)
                            continue;
                        q.push(make_pair(x+dx[k],y+dy[k]));
                        arr[x+dx[k]][y+dy[k]]=0;
                    }
                }
                if(sum>max)
                    max=sum;
                sum=0;
            }   
        }
    }
    printf("%d\n%d",cnt,max);
}
