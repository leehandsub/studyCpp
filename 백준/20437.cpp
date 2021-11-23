#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    int n;
    int find=0;
    int k;
    int max=-1,min=999999999;
    string in;
    vector<vector<int>> arr(26);
    vector<vector<int>> arr2(26);
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    { 
        cin>>in;
        cin>>k;
        for(int j=0;j<in.size();j++)
        {
            arr[in[j]-'a'].push_back(j);
            arr2[in[j]-'a'].push_back(j);
            if(arr[in[j]-'a'].size()==k)
            {
                if(max<arr[in[j]-'a'].back()-arr[in[j]-'a'].front()+1)
                {
                    max=arr[in[j]-'a'].back()-arr[in[j]-'a'].front()+1;
                    arr[in[j]-'a'].erase(arr[in[j]-'a'].begin());
                }
                find=1;
            }
            if(arr2[in[j]-'a'].size()==k)
            {
                if(min>arr2[in[j]-'a'].back()-arr2[in[j]-'a'].front()+1)
                {
                    min=arr2[in[j]-'a'].back()-arr2[in[j]-'a'].front()+1;
                    arr2[in[j]-'a'].erase(arr2[in[j]-'a'].begin());
                }
                find=1;
            }
            
        }
        if(find==0)
            printf("-1\n");
        else
            printf("%d %d\n",min,max);
        find=0;
        for(int j=0;j<arr.size();j++)
        {
            arr[j].clear();
            arr2[j].clear();
        }
    }
}
