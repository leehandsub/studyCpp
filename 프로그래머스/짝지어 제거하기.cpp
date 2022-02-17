#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    stack<char> st;
    
    for(int i=0;i<s.size();i++)
    {
        if(st.empty()==1)
        {
            st.push(s[i]);
            continue;
        }
        if(st.top()==s[i])
            st.pop();
        else
            st.push(s[i]);
    }
    if(st.empty()==1)
        answer=1;

    /*int i=0;
    int size=s.size();
    while(i+1<size)
    {
        if(s[i]==s[i+1])
        {
            s.erase(i,2);
            if(i!=0)
                i--;
        }
        else
        {
            i++;
        }
        if(s.size()==0)
        {
            answer=1;
            break;
        }

    }*/

    return answer;
}//처음에 그냥 문자열 지우면서 놀다가 시간으로 혼나가지고 스택을 사용
