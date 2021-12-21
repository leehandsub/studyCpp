#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n,m;
    vector<int> arr;
    vector<int> vit;

    scanf("%d %d",&n,&m);
    
    for(int i=0;i<n;i++)
    {
        arr.push_back(i+1);
        vit.push_back(0);
    }
    
    for(int i=0;i<m;i++)
    {
        vit[i]=1;
    }
    
    do{
        for(int i=0;i<n;i++)
        {
            if(vit[i]==1)
            {
                printf("%d ",arr[i]);
            }
        }
        printf("\n");
        
    }while(prev_permutation(vit.begin(),vit.end()));
    
}
