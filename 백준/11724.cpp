#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> adj[1001];
int vit[1001];

int main(void)
{
    int n,m;
    int x,y;
    int cnt=0;
    int now;
    queue <int> q;
    scanf("%d %d",&n,&m);
    
    while(m--)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(vit[i]==1)
            continue;
        cnt++;
        q.push(i);
        vit[i]=1;
        while(!q.empty())
        {
            now=q.front();
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
    printf("%d",cnt);
}
