#include <string>
#include <vector>
#include <stack>

using namespace std;

bool good(string s)
{
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==']')
        {
            if(st.top()=='[')
                st.pop();
            else return false;
        }
            
        else if(s[i]==')')
        {
            if(st.top()=='(')
                st.pop();
            else return false;
        }
            
        else if(s[i]=='}')
        {
            if(st.top()=='{')
                st.pop();
            else return false;
        }
        
        else{
            st.push(s[i]);
        }
    }
    if(st.empty()==1)return true;
    else return false;
}

int solution(string s) {
    int answer = 0;
    string now="";
    for(int i=0;i<s.size();i++)
    {
        now=s.substr(0,1);
        s.erase(0,1);
        s+=now;
        if(good(s)==true)
            answer++;
        now="";
    }
    return answer;
}
