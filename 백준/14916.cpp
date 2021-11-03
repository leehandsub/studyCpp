#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2];

int main(void)
{
    int n;
    int ans=-1;
    scanf("%d",&n);
    
    arr[0]=n/5;
    arr[1]=(n%5)/2;
    while(arr[0]!=-1)
    {
        if(n==arr[0]*5+arr[1]*2)
        {
            ans=arr[0]+arr[1];
            break;
        }
        arr[0]=arr[0]-1;
        arr[1]=(n-5*arr[0])/2;
    }
        
    printf("%d",ans);
}
