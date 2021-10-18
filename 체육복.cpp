#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    vector<int> arr(n+1,1);
    
    for(int i=0;i<lost.size();i++)
    {
        arr[lost[i]]--;
    }
    for(int i=0;i<reserve.size();i++)
    {
        arr[reserve[i]]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==0&arr[i-1]==2)
        {
            arr[i]++;
            arr[i-1]--;
        }
        if(arr[i]==0&arr[i+1]==2)
        {
            arr[i]++;
            arr[i+1]--;
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        if(arr[i]!=0)
            answer++;
    }
    
    return answer;
}
