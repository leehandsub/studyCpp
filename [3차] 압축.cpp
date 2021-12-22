#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string,int> temp;
    char c='A';
    string now="";
    int cnt=27;
    for(int i=0;i<26;i++)
    {
        now.push_back(c+i);
        temp.insert(make_pair(now,i+1));
        now="";
    }
    for(int i=0;i<msg.size();i++)
    {
        now.push_back(msg[i]);
        while(temp.count(now))
        {
            if(msg.size()==i)
                break;
            now.push_back(msg[++i]);
        }

        temp.insert(make_pair(now,cnt));
        cnt++;
        now.pop_back();
        answer.push_back(temp[now]);
        i--;
        now.clear();
    }
    
    return answer;
}
