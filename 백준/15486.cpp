#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;

int dp[1500002];
int main(void) {
	
	int n,m;
	int t;
	int ma=0;
	vector<pair<int,int>> arr;
	scanf("%d",&t);
	arr.push_back(make_pair(-1,-1));
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&n,&m);
        arr.push_back(make_pair(n,m));
    }
    
    for(int i=1;i<=t+1;i++)
    {
        if(ma<dp[i])
            ma=dp[i];
        if(arr[i].first+i>t+1)
            continue;
        dp[arr[i].first+i]=max(dp[i]+arr[i].second,dp[arr[i].first+i]);
    }
    printf("%d",ma);
}//테케 4가 안됨 왜안되는지 몰겟다...
