#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long price[100001];
long long way[100001];

int main(void)
{
    int n;
    long long answer=0;
    long long now=0;
    
    scanf("%d",&n);
    
    for(int i=0;i<n-1;i++)
    {
        scanf("%lld",&way[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&price[i]);
    }
    
    now=price[0];
    for(int i=1;i<n;i++)
    {
        answer+=way[i-1]*now;
        if(now>price[i])
        {
            now=price[i];
        }
    }
    printf("%lld",answer);
}
