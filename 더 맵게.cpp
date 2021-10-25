#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = -1;
    priority_queue<int, vector<int>, greater<int>> pq;
    int find=0;
    int now=0;
    int cnt=0;
    //sort(scoville.begin(),scoville.end());
    for(int i=0;i<scoville.size();i++)
    {
        pq.push(scoville[i]);
    }
    while(pq.size()!=1)
    {
        if(pq.top()>=K)
            break;
        else
        {
            cnt++;
            now+=pq.top();
            pq.pop();
            now+=(pq.top()*2);
            pq.pop();
            pq.push(now);
        }
        now=0;        
    }
    if(pq.top()>=K)
        answer=cnt;
    return answer;
    
}
