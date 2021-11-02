#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

string change(int n,int now)
{
    string ans="";
    int num=1;
    if(now==0)
        return "0";
    while(now!=0)
    {
        num=now%n;
        if(num>=0&&num<10)
            ans+=to_string(num);
        else if(num==10)
            ans+="A";
        else if(num==11)
            ans+="B";
        else if(num==12)
            ans+="C";
        else if(num==13)
            ans+="D";
        else if(num==14)
            ans+="E";
        else if(num==15)
            ans+="F";
        now/=n;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string game="";
    int i=0;//지금 차례
    int now=0;//숫자
    int num=0;//t세기
    for(int j=0;j<t;j++)
    {
        answer+=" ";
    }
    while(num!=t)
    {
        if(game[i]=='\0'||game.empty())
        {
            game+=change(n,now);
            now++;
        }
        if(m==p&&(i+1)%m==0)
        {
            answer[num]=game[i];
            num++;
        }
        if((i+1)%m==p)
        {
            answer[num]=game[i];
            num++;
        }     
        i++;
    }
    
    return answer;
}
