#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int a,b,c,m;
    int now=0;//피로도
    int work=0;//work
    scanf("%d %d %d %d",&a,&b,&c,&m);
    
    for(int i=0;i<24;i++)
    {
        if(m<now+a)
        {
            now=now-c;
            if(now<0)
                now=0;
        }
        else
        {
            now=now+a;
            work+=b;
        }
    }
    printf("%d",work);

}
