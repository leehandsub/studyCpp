#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(void)
{
    char arr[3][10]={{'q','w','e','r','t','y','u','i','o','p'},
                    {'a','s','d','f','g','h','j','k','l',-1},
                    {'z','x','c','v','b','n','m',-1,-1}};
    char a,b;
    int ax,ay;
    int bx,by;
    int cnt=0;
    int anum=0,bnum=0;
    char find[101];
    
    scanf("%c %c",&a,&b);
    scanf("%s",find);
    
    for(int j=0;j<3;j++)
    {
        for(int k=0;k<10;k++)
        {
            if(arr[j][k]==a)
            {
                ax=k;
                ay=j;
            }
            if(arr[j][k]==b)
            {
                bx=k;
                by=j;
            }
        }
    }
    for(int i=0;find[i]!='\0';i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<10;k++)
            {
                if(arr[j][k]==find[i])
                {
                    if((j<2&&k<5)||(j==2&&k<4))//자음
                    {
                        cnt+=(abs(ax-k)+abs(ay-j)+1);
                        ax=k;
                        ay=j;
                    }
                    else
                    {
                        cnt+=(abs(bx-k)+abs(by-j)+1);
                        bx=k;
                        by=j;
                    }
                    j=4;
                    break;
                }
            }
        }
    }
    printf("%d",cnt);
    
}
