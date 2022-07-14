/*
문제 : 프로그래머스 lv2 더 맵게
피드백 : priority_queue<int, vector<int>, greater<int>> pq;사용해서 값이 들어오면
알아서 맨위에 작은값이 오게 했다.
*/

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
