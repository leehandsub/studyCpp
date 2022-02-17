#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    string now="";
    char find;
    int cnt=0;
    priority_queue <int> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    answer.push_back(0);
    answer.push_back(0);
    for(int i=0;i<operations.size();i++)
    {
        find=operations[i][0];
        now="";
        for(int j=2;j<operations[i].size();j++)
        {
            now+=operations[i][j];
        }
        if(find=='I')
        {
            pq.push(stoi(now));
            pq2.push(stoi(now));
            cnt++;
        }
        else
        {
            cnt--;
            if(cnt<=0)
            {
                cnt=0;
                pq = priority_queue <int>();
                pq2 = priority_queue <int, vector<int>, greater<int>>();
                continue;
            }
            if(stoi(now)==1)
                pq.pop();

            else if(stoi(now)==-1)  
                pq2.pop();
        }


    }
    
    if(cnt==0)
        return answer;
    else
    {
        answer[0]=pq.top();
        answer[1]=pq2.top();
        return answer;
    }
    
}
