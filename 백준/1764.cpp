#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(void)
{
    int n,m,k;
    string a;
    set<string> s;
    vector<string> arr;
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n+m;i++)
    {
        cin>>a;
        if(s.count(a)==1)
            arr.push_back(a);
        else
            s.insert(a);
    }
    sort(arr.begin(),arr.end());
    printf("%d\n",arr.size());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\n";
    }
}
