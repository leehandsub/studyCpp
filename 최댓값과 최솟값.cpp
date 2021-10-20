#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    string temp="";
    int now=0;
    int i=0;
    int max=-9999999;
    int min=9999999;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            temp+=s[i++];
            while(1)
            {
                if(s[i]==' '||s[i]=='\0')
                    break;
                temp+=s[i++];
            }
            if(stoi(temp)>max)
                max=stoi(temp);
            if(stoi(temp)<min)
                min=stoi(temp);
        }
        else if(s[i]!=' ')
        {
            temp+=s[i++];
            while(1)
            {
                if(s[i]==' '||s[i]=='\0')
                    break;
                temp+=s[i++];
            }
            if(stoi(temp)>max)
                max=stoi(temp);
            if(stoi(temp)<min)
                min=stoi(temp);
        }
        temp="";
        if(i>=s.size())
            break;
    }
    answer+=to_string(min);
    answer+=" ";
    answer+=to_string(max);
    return answer;
}
