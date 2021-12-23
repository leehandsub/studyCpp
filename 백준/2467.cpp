#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(void) 
{
    int n,m;
    int x,y;
    int min=2147483641;
    int left,right,mid;;
    vector<int> arr;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        arr.push_back(x);
    }
    left=0;
    right=n-1;
    while(left<right)
    {
        mid=arr[left]+arr[right];
        if(min>abs(mid))
        {
            min=abs(mid);
            x=arr[left];
            y=arr[right];
        }
        else
        {
            if(mid>0)
                right--;

            else
                left++;
        }
    }
    
    printf("%d %d",x,y);

}
