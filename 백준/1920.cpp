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
    int left=0,right,mid;
    int now;
    vector<int> arr;

    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        arr.push_back(now);
    }
    sort(arr.begin(),arr.end());
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&now);
        left=0;
        right=n-1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(now==arr[mid])
            {
                printf("1\n");
                break;
            }
            else if(arr[mid]>now)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        if(left>right)
            printf("0\n");
    }
    
}
