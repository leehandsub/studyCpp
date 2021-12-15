#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[1001][1001];
int vit[1001][1001];

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

struct Data{
    int x;
    int y;
    int now;
    Data(int a,int b,int c)
    {
        x=a;
        y=b;
        now=c;
    }
};

int main(void)
{
    int n,m;
    int x,y;
    string s;
    int ch;
    queue<Data> q;
    
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++)
    {
        getline(cin,s);
        
        for(int j=0;j<s.size();j++)
        {
            arr[i][j]=s[i]-'0';
        }
    }
    //arr[0][0]=1;
    vit[0][0]=1;
    q.push(Data(0,0,1));
    while(!q.empty())
    {
        x=q.front().x;
        y=q.front().y;
        ch=q.front().now;
        printf("%d %d\n",x,y);
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=m||vit[x+dx[i]][y+dy[i]]==1)
                continue;
            if(ch==0&&arr[x+dx[i]][y+dy[i]]==1)
                continue;
            if(ch==1&&arr[x+dx[i]][y+dy[i]]==1)
                q.push(Data(x+dx[i],y+dy[i],0));
            else
                q.push(Data(x+dx[i],y+dy[i],ch));
            arr[x+dx[i]][y+dy[i]]=1;
            vit[x+dx[i]][y+dy[i]]=1;
        }
    }
    
    printf("%d",vit[n-1][m-1]);
    
}
