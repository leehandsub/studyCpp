/*
문제 : 프로그래머스 lv2 기능개발
피드백 : 큐로 먼저 잇는것이 다될때까지 기다리다가 한번에 출력하게 했다.
*/

#include <string>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int now=0;
    int cnt=0;
    for(int i=0;i<progresses.size();i++)
    {
        while(progresses[i]<100)
        {
            progresses[i]+=speeds[i];
            cnt++;
        }
        q.push(cnt);
        cnt=0;
    }
    now=q.front();

    while(!q.empty())
    {
        if(now>=q.front())
        {
            cnt++;
            q.pop();
        }
        else
        {
            answer.push_back(cnt);
            cnt=0;
            now=q.front();
        }
    }
    answer.push_back(cnt);
    return answer;
}
