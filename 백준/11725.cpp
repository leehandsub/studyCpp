#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr[100001];
int vit[100001];
int pa[100001];

int main(void)
{
    int n,m;
    int x,y;
    int now;
    queue<int> q;
    
    scanf("%d",&n);
    
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&x,&y);
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    
    q.push(1);
    vit[1]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=0;i<arr[now].size();i++)
        {
            if(vit[arr[now][i]]==1)
                continue;
            q.push(arr[now][i]);
            vit[arr[now][i]]=1;
            pa[arr[now][i]]=now;
        }
    }
    for(int i=2;i<=n;i++)
    {
        printf("%d\n",pa[i]);
    }
}
