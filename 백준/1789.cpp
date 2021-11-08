#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main(void)
{
    long long S;
    int now=1;
    int cnt=0;
    long long sum=0;
    scanf("%lld",&S);
    
    while(1)
    {
        sum+=now;
        now++;
        cnt++;
        if(sum>S)
        {
            cnt--;
            break;
        }
        
    }
    printf("%d",cnt);
}
