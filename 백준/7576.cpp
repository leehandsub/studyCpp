#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Toma {
	int x;
	int y;
	int cnt;
	Toma(int a, int b,int c) {
		x= a;
		y = b;
		cnt= c;
	}
};

int arr[1001][1001];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main(void)
{
    int n,m;
    int x,y,cnt;
    int num=0;
    queue<Toma> q;//0갯수 찾고, 1을 만낫을 때 최대일수세기
    scanf("%d %d",&m,&n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1)
            {
                q.push(Toma(i,j,0));
                arr[i][j]=-1;
            }
            else if(arr[i][j]==0)
                num++;
        }
    }
    
    while(!q.empty())
    {
        x=q.front().x;
        y=q.front().y;
        cnt=q.front().cnt;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(arr[x+dx[i]][y+dy[i]]==-1||x+dx[i]<0||x+dx[i]>=n||y+dy[i]<0||y+dy[i]>=m)
                continue;
            q.push(Toma(x+dx[i],y+dy[i],cnt+1));
            arr[x+dx[i]][y+dy[i]]=-1;
            num--;
        }
        
    }
    if(num==0)
    {
        printf("%d",cnt);
    }
    else
    {
        printf("-1");
    }
}
