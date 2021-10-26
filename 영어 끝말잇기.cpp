#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> temp;
    string now="";
    answer.push_back(0);
    answer.push_back(0);
    for(int i=0;i<words.size();i++)
    {
        if(i!=0)
            now=words[i-1];
        if(temp.count(words[i])==1||now[now.size()-1]!=words[i][0]&&i!=0)
        {
            if(((i+1)%n)==0)
                answer[0]=n;
            else
                answer[0]=(i+1)%n;
            answer[1]=i/n+1;
            break;
        }
        else
            temp.insert(words[i]);
    }

    return answer;
}
