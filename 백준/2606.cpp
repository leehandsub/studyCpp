#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr[101];
int vit[101];

int main(void)
{
    int n,m;
    int x,y;
    int now;
    int sum=0;
    queue<int> q;
    scanf("%d",&n);
    scanf("%d",&m);
   
    for(int i=0;i<m;i++)
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
            sum++;
        }
    }
    
    printf("%d",sum);
}
