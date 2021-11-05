#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long right=(long long)times[times.size()-1]*n;//내가 생각했던거보다 시작 크기를 더 많이 줘야했다.
    long long left=0;
    long long mid=0;
    long long now=0;
    while(left <= right)
    {
        mid=(left+right)/2;
        for(int i=0;i<times.size();i++)
        {
            now+=mid/(long long)times[i];
        }
        if(n>now)
            left=mid+1;
        else
        {
            answer=mid;
            right=mid-1;
        }
        now=0;
    }
    
    if(n/times.size()==0)
        mid=times[n-1];
    return answer;
}
