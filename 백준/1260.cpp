#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector<int> adj[1001];
int vit[1001];

void dfs(int now)
{
    vit[now]=1;
    printf("%d ",now);
    for(int i=0;i<adj[now].size();i++)
    {
        if(vit[adj[now][i]]==1)
        continue;
        dfs(adj[now][i]);
    }
}

int main(void)
{
    int n,m;
    int start;
    int x,y;
    int cnt=0;
    int now;
    queue <int> q;
    scanf("%d %d %d",&n,&m,&start);
    
    while(m--)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
    }
    dfs(start);
    
    printf("\n");
    
    for(int i=0;i<n+1;i++)
    {
        vit[i]=0;
    }

    q.push(start);
    vit[start]=1;
    while(!q.empty())
    {
        now=q.front();
        printf("%d ",now);
        q.pop();
        for(int j=0;j<adj[now].size();j++)
        {
            if(vit[adj[now][j]]==1)
                continue;
            q.push(adj[now][j]);
            vit[adj[now][j]]=1;
        }
    }

}
