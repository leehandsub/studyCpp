#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}

int main(void)
{
    int n,m;
    int x,y;
    int cnt=0;
    vector <pair<int,int>> arr;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {   
        scanf("%d %d",&x,&y);
        arr.push_back(make_pair(x,y));
    }
    sort(arr.begin(),arr.end(),compare);
    x=0;
    for(int i=0;i<n;i++)
    {
        if(x>arr[i].first)
            continue;
        x=arr[i].second;
        cnt++;
    }
    printf("%d",cnt);
}
