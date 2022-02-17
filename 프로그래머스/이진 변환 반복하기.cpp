#include <string>
#include <vector>
#include <iostream>
using namespace std;

string con(int now)
{
    string s;
    while (now > 0) {
		if (now % 2 == 1) s = "1" + s;
		else s = "0" + s;
		now >>= 1;
	}
    return s;
}

vector<int> solution(string s) {
    vector<int> answer;
    int i=0;
    int cnt=0;
    int now=0;
    string find=s;
    cout<<find;
    while(find.size()!=1)
    {
        i++;
        for(int j=0;j<find.size();j++)
        {
            if(find[j]=='0')
                now++;
        }
        cnt+=now;
        now=find.size()-now;
        find=con(now);
        now=0;
        
    }
    answer.push_back(i);
    answer.push_back(cnt);
    
    return answer;
}
