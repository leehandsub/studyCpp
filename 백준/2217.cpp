#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n,m;
    int max=0;
    int now=0;
    vector<int> arr;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        arr.push_back(m);
    }
    sort(arr.begin(),arr.end(),greater<>());
    
    for(int i=0;i<n;i++)
    {
        now=arr[i]*(i+1);
        if(max<now)
            max=now;
    }
    printf("%d",max);
}
