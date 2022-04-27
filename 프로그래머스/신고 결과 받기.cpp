#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    vector<int> cnt;
    string temp;
    unordered_map<string, int> hash;
    vector<string> attack;
    vector<string> receive;
    
    sort(report.begin(),report.end());
    report.erase(unique(report.begin(),report.end()),report.end());
    
    for(int i=0;i<id_list.size();i++)
    {
        hash.insert(make_pair(id_list[i],i));
        answer.push_back(0);
        cnt.push_back(0);
    }
    
    for(int i=0;i<report.size();i++)
    {
        for(int j=0;j<report[i].size();j++)
        {
            if(report[i][j]==' ')
            {
                attack.push_back(temp);
                temp.clear();
                continue;
            }
            temp.push_back(report[i][j]);    
        }
        receive.push_back(temp);
        cnt[hash[temp]]++;
        temp.clear();
    }
    
    for(int i=0;i<report.size();i++)
    {
        if(cnt[hash[receive[i]]]>=k)
        {
            answer[hash[attack[i]]]++;
        }
    }
    
    return answer;
}
