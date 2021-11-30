#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void)
{
    int n,m;
    int j=1;
    string in;
    string ans="";
    string now="";
    getline(cin, in);
    for(int i=0;i<in.size();i++)
    {
        if(in[i]=='<')
        {
            j=i;
            while(1)
            {
                if(in[j]=='>')
                    break;
                j++;
            }
            now=in.substr(i,j-i+1);
            
            i=j;
        }
        else if(in[i]==' ')
        {
            now=" ";
        }
        else
        {
            j=i;
            while(1)
            {
                if(j>=in.size()||in[j]==' '||in[j]=='<')
                    break;
                j++;
            }
            now=in.substr(i,j-i);
            reverse(now.begin(),now.end());
            i=j-1;
        }
        ans=ans+now;
        now="";
    }
    
    cout<<ans;
}
