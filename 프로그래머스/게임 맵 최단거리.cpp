#include<vector>
#include <stdio.h>
#include <queue>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };
int arr[101][101];

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    queue<pair<int,int>> q;
    int x,y;
    
    arr[maps.size()-1][maps[0].size()-1]=-1;
    q.push(make_pair(0,0));
    maps[0][0]=0;
    arr[0][0]=1;
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(x+dx[i]<0||x+dx[i]>=maps.size()||y+dy[i]<0||y+dy[i]>=maps[0].size()||maps[x+dx[i]][y+dy[i]]==0)
                continue;
            q.push(make_pair(x+dx[i],y+dy[i]));
            arr[x+dx[i]][y+dy[i]]=arr[x][y]+1;
            maps[x+dx[i]][y+dy[i]]=0;
        }
    }

    return arr[maps.size()-1][maps[0].size()-1];
}
