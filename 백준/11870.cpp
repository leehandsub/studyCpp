#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> arr;
vector<int> temp;
int main(void)
{
    int n,m;
    int now;
    int cnt=0;
    unordered_map<int,int> um;

    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        arr.push_back(now);
        temp.push_back(now);
    }

    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++)
    {
        if(um.count(temp[i])==0)
        {
            um.insert(make_pair(temp[i],cnt));
            cnt++;
        }
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=um[arr[i]];
        printf("%d ",arr[i]);
    }
}
