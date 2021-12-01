#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void)
{
    int n;
    int now;
    long long answer=0;
    vector<int> arr;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        arr.push_back(now);
    }
    now=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++)
    {
        now+=arr[i];
        answer+=(long long)now;
    }
    printf("%lld",answer);
}
