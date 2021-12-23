#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(void) 
{
    int n,m;
    int x,y=0;
    int i;
    int ma=2100000000;
    int now=0;
    int find=0;
    vector<int> arr;
    vector<int> dp;
    
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr.push_back(x);
    }
    x=0;
    while(x<n)
    {
        now+=arr[x];
        if(now>=m)
            break;
        x++;
    }

    while(x<n)
    {
        find=x-y+1;
        if(ma>find)
        {
            find=ma;
        }
        while(1)
        {
            now-=arr[y];
            if(now<m)
                break;
            y++;
        }
        x++;
        while(1)
        {
            now+=arr[x];
            if(now>=m)
                break;
            x++;
        }
 
    }
    if(ma==2100000000)
        printf("%d",0);
    else
        printf("%d",ma);
}
