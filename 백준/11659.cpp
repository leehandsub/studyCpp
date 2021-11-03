#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
    int i,j;
    int n,m;
    int now=0;
    scanf("%d %d",&n,&m);
    vector <int> arr;
    arr.push_back(0);
    for(int k=1;k<=n;k++)
    {
        scanf("%d",&now);
        arr.push_back(now+arr[k-1]);
    }
    
    for(int k=0;k<m;k++)
    {
        scanf("%d %d",&i,&j);
        printf("%d\n",arr[j]-arr[i-1]);
    }

}
