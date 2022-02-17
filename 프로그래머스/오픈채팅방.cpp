#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> temp;
    int j=0;
    string now="";
    string name="";
    for(int i=0;i<record.size();i++)
    {   
        now="";
        name="";
        if(record[i][0]=='E')
        {
            j=6;
            while(record[i][j]!=' ')
            {
                now+=record[i][j];
                j++;
            }
        }
        else if(record[i][0]=='C')
        {
            j=7;
            while(record[i][j]!=' ')
            {
                now+=record[i][j];
                j++;
            }
        }
        else
            continue;
        j++;
        while(j<=record[i].size())
        {
            name+=record[i][j];
            j++;
        }

        if(temp.count(now)==0)
            temp.insert(make_pair(now,name));
        else
            temp[now]=name;

    }
    for(int i=0;i<record.size();i++)
    {   
        now="";
        j=0;
        if(record[i][0]=='E')
        {
            j=6;
            while(record[i][j]!=' ')
            {
                now+=record[i][j];
                j++;
            }
            name=temp[now].substr(0,temp[now].size()-1)+"님이 들어왔습니다.";
        }
        else if(record[i][0]=='L')
        {
            j=6;
            while(record[i].size()!=j)
            {
                now+=record[i][j];
                j++;

            }
            name=temp[now].substr(0,temp[now].size()-1)+"님이 나갔습니다.";
        }    
        else
            continue;
        
        answer.push_back(name);   
    }

    return answer;
}
