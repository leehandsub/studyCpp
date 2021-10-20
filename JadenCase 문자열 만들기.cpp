#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    s[0]=toupper(s[0]);
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]==' '&&isalpha(s[i+1])!=0)
        {
           
            s[i+1]=toupper(s[i+1]);
        }
        else if(s[i-1]!=' '&&isalpha(s[i])!=0)
        {
            s[i]=tolower(s[i]);
        }
    }
    answer+=s;
    return answer;
}
