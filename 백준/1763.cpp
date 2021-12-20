#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<pair<int,int>> arr[20001];
int vit[20001];

int main(void)
{
    int n,m;
    int start;
    int ne,nw;
    int x,y,w;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    scanf("%d %d",&n,&m);
    scanf("%d",&start);
    
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&x,&y,&w);
        arr[x].push_back(make_pair(y,w));
    }
    
    for(int i=0;i<20001;i++)
    {
        vit[i]=20000000;
    }
    pq.push(make_pair(0,start));
    vit[start]=0;
    while(!pq.empty())
    {
        x=pq.top().first;
        y=pq.top().second;
        pq.pop();
        for(int i=0;i<arr[y].size();i++)
        {
            ne=arr[y][i].first;
            nw=arr[y][i].second;
            
            if(vit[ne]>x+nw)
            {
                vit[ne]=x+nw;
                pq.push(make_pair(vit[ne],ne));
            }
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(vit[i]==20000000)
            printf("INF\n");
        else
            printf("%d\n",vit[i]);
    }
}
