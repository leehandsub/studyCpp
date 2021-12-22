#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int arr[101][101];
int vit[101][101];

int main(void)
{
    int n,m;
    int x,y;
    int now;
    int sum=0;
    int cnt=0;
    vector<int> ans;
    queue<pair<int,int>> q;
    scanf("%d",&n);
    scanf("%d",&m);
   
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1)
            {
                sum++;
            }
        }
    }
    ans.push_back(0);
    while(sum)
    {
        q.push(make_pair(cnt,cnt));
        vit[cnt][cnt]=1;
        ans.push_back(sum);
        while(!q.empty())
        {
            y=q.front().first;
            x=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                if(x+dx[i]<cnt||x+dx[i]>=m||y+dy[i]<cnt||y+dy[i]>=n||vit[y+dy[i]][x+dx[i]]==1)
                    continue;
                if(arr[y+dy[i]][x+dx[i]]==1)
                {
                    arr[y+dy[i]][x+dx[i]]=0;
                    vit[y+dy[i]][x+dx[i]]=1;
                    sum--;
                    continue;
                }
                q.push(make_pair(y+dy[i],x+dx[i]));
                vit[y+dy[i]][x+dx[i]]=1;
            }
        }
        for(int i=cnt;i<n;i++)
        {
            for(int j=cnt;j<m;j++)
            {
                vit[i][j]=0;
            }
        }
        cnt++;
    }
    printf("%d\n%d",cnt,ans.back());
}
