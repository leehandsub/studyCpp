#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

int main(void)
{
    int t;
    int mode,now,wh;
    set<int> s;
    vector<string> arr;
    int n,m;//n기차이의 개숫, m 명령의 갯수
    scanf("%d %d",&n,&m);
    
    
    for(int i=0;i<n;i++)
    {
        arr.push_back("00000000000000000000");
    }
    
    for(int i=0;i<m;i++)
    {
        scanf("%d",&mode);
        if(mode==1)
        {
            scanf("%d %d",&now,&wh);
            arr[now-1][wh-1]='1';
        }
        else if(mode==2)
        {
            scanf("%d %d",&now,&wh);
            arr[now-1][wh-1]='0';
        }
        else if(mode==3)
        {
            scanf("%d",&now);
            arr[now-1].erase(19,1);
            arr[now-1].insert(0,"0");
        }
        else if(mode==4)
        {
            scanf("%d",&now);
            arr[now-1].erase(0,1);
            arr[now-1].push_back('0');
        }
    }
    
    for(int i=0;i<n;i++)
    {
        s.insert(stoi(arr[i],nullptr,2));
    }
    printf("%d",s.size());
}
