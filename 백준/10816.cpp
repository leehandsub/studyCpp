#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <unordered_map>

using namespace std;

int arr[500001];

int main(void) 
{
    int n,m;
    int x,y=0;
    unordered_map<int,int> temp;
    int now;

    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        if(temp.count(now)==0)
        {
            temp.insert(make_pair(now,1));
        }
        else
        {
            temp[now]++;
        }
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&now);
        printf("%d ",temp[now]);
    }
}
