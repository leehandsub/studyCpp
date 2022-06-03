/*

문제 : 백준 숨바꼭질
시간 : ??(복기)
ide 활용 : 
질문 보기 : 
피드백 : bfs를 활용했다.
갈 수 있는 경우의 수에 지나온 횟수를 저장하면서 왔다.
다시보니 암것도 모르면 풀 수 있을까 생각이 든다.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[200001];

int main(void)
{
    int n,m,k;
    queue<pair<int,int>> q;
    int cnt=0,now;
    scanf("%d %d",&n,&m);
    
    q.push(make_pair(n,0));
    arr[n]=1;
    while(!q.empty())
    {
        now=q.front().first;
        cnt=q.front().second;
        //printf("%d ",now);
        q.pop();
        if(now*2<200000&&arr[now*2]==0)
        {
            q.push(make_pair(now*2,cnt+1));
            arr[now*2]=1;
        }
        if(now-1>=0&&arr[now-1]==0)
        {
            q.push(make_pair(now-1,cnt+1));
            arr[now-1]=1;
        }
        if(arr[now+1]==0)
        {
            q.push(make_pair(now+1,cnt+1));
            arr[now+1]=1;
        }
        if(now==m)
        {
            printf("%d",cnt);
            break;
        }
    }
}
