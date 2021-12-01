#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int answer=0;
    char now;
    int b=1,r=1;
    string in;
    scanf("%d",&n);
    cin>>in;
    
    now=in[0];
    if(in[0]=='R')
        b++;
    if(in[0]=='B')
        r++;
    for(int i=1;i<in.size();i++)
    {
        if(now!=in[i]&&in[i]=='B')
        {
            now=in[i];
            r++;
        }
        if(now!=in[i]&&in[i]=='R')
        {
            now=in[i];
            b++;
        }
    }
    printf("%d",min(r,b));
    
}
