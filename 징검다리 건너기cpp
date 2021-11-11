#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int right=*max_element(stones.begin(),stones.end());
    int mid=0;
    int left=*min_element(stones.begin(),stones.end());
    int cnt=0;
    int mode=0;
    while(left<=right)
    {
        mid=(right+left)/2;
        printf("%d ",mid);
        for(int i=0;i<stones.size();i++)
        {
            if(stones[i]-mid<=0)
                cnt++;
            else
                cnt=0;
            if(cnt>=k)
            {
                mode=1;
                break;
            }
            /*else if(cnt==k)
            {
                mode=2;
                break;
            }*/
                
        }
        if(mode==1)
            right=mid-1;
        else if(mode==0)
            left=mid+1;
        /*else
        {
            return mid;
        }*/
        //printf("%d ",mid);
        mode=0;
        cnt=0;
    }
    
    return left;
}//다시 풀어볼수있으면 풀어보기
