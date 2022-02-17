#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int i=0,j=0;
    queue<string> q;
    unordered_map<string, int> temp;
    int find=99999999;
    int x=1,y=0;
    int cnt=0;
    string now="";
    for(int i=0;i<gems.size();i++)
    {
        temp.insert(make_pair(gems[i],0));
    }
    

    while(1)
    {
        q.push(gems[j]);
        if(temp[gems[j]]==0)
        {
            cnt++;
        }
        temp[gems[j]]++;
        if(cnt==temp.size())
        {
            x+=(j+1-q.size());
            y=j+1;
            break;
        }
        j++;
    }
    while(j<gems.size())
    {
        if(temp[q.front()]>1)
        {
            temp[q.front()]--;
            q.pop();
            if(find>q.size())
            {
                printf("%d",temp[q.front()]);
                find=q.size();
                y=j+1;
                x=j-q.size()+2;
            }
        }
        else
        {
            j++;
            if(q.front()!=gems[j])
            {
                now=q.front();
                while(j<gems.size())
                {
                    q.push(gems[j]);
                    temp[gems[j]]++;
                    if(q.back()==now)
                        break;
                    j++;
                }
                
            }
            else
            {
                q.push(gems[j]);
                q.pop();
            }
        }
    }
       
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}
