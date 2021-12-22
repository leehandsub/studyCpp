#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int arr[1025];
int ans[1025];
int n;
int num=1;
void order(int now)
{
    if(now>pow(2,n)-1)
        return;
    order(now*2);
    ans[now]=arr[num++];
    order(now*2+1);
}

int main(void)
{
   // int n,m;
    int x,y;
    int now=1;
    int d=1;

    scanf("%d",&n);
    
    for(int i=1;i<pow(2,n);i++)
    {
        scanf("%d",&arr[i]);
    }
    order(1);
    for(int i=1;i<pow(2,n);i++)
    {
        printf("%d ",ans[i]);
        if(i==now)
        {
            printf("\n");
            now+=pow(2,d);
            d++;
        }
    }
    
}
