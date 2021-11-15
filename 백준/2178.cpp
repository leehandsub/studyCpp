#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

int vit[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

using namespace std;

int main(void)
{
    int n,m;
    int x,y;
    string st[101];
    queue<pair<int,int>> q;
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++)
    {
        cin>>st[i];   
    }
    
    q.push(make_pair(0,0));
    vit[0][0]=1;
    st[0][0]='0';
    
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++)
        {
            if(x+dx[k]<0||x+dx[k]>=n||y+dy[k]<0||y+dy[k]>=m||st[x+dx[k]][y+dy[k]]=='0')
                continue;
            q.push(make_pair(x+dx[k],y+dy[k]));
            st[x+dx[k]][y+dy[k]]='0';
            vit[x+dx[k]][y+dy[k]]=vit[x][y]+1;
        }
    }

    printf("%d",vit[n-1][m-1]);
}
