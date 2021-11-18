#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    string now="";
    string now2="";
    unordered_map <string,int> temp;
    int x=0,y=0;
    for(int i=0;i<dirs.size();i++)
    {
        now="";
        now2="";
        now+=to_string(x);
        now+=to_string(y);
        now2+=now;
        if(dirs[i]=='U'&&y!=5)
        {
            y++;
        }
        else if(dirs[i]=='D'&&y!=-5)
        {
            y--;
        }
        else if(dirs[i]=='R'&&x!=5)
        {
            x++;
        }
        else if(dirs[i]=='L'&&x!=-5)
        {
            x--;
        }
        else
            continue;
        now+=to_string(x);
        now+=to_string(y);
        now2=to_string(y)+now2;
        now2=to_string(x)+now2;
        if(temp.count(now)==0)
        {
            temp.insert(make_pair(now,1));
            answer++;
            temp.insert(make_pair(now2,1));
        }
    }
    
    return answer;
}
