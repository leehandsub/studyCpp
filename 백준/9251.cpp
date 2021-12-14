#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1001][1001];

int main(void)
{
    int n,m;
    string now="";
    int ma=0;;
    string s;
    string d;
    
    cin>>s;
    cin>>d;
    
    for(int i=1;i<=d.size();i++)
    {
        for(int j=1;j<=s.size();j++)
        {
            if(d[i-1]==s[j-1])
            {
                arr[i][j]=arr[i-1][j-1]+1;
            }
            else
            {
                arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
            if(arr[i][j]>ma)
            {
                ma=arr[i][j];
            }
        }
    }
    /*int i=d.size();
    int j=s.size();
    while(1)
    {
        if(arr[i][j]==0)
            break;
        if(arr[i][j]==arr[i-1][j])
        {
            i--;
        }
        else if(arr[i][j]==arr[i][j-1])
        {
            j--;
        }
        else
        {
            i--;
            j--;
        }
        if(s[j]==d[i])
        {
            now.push_back(s[j]);
        }
        cout<<now<<"\n";
    }
    reverse(now.begin(),now.end());
    cout<<now;*///출력도 구현 해봄
    printf("\n%d",ma);
}
