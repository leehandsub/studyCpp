#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
   int n;
   stack <char> s;
   string now;
   int mode=1;
   
   scanf("%d",&n);
   
   for(int i=0;i<n;i++)
   {
        cin>>now;
        for(int j=0;j<now.size();j++)
        {
            if(now[j]=='(')
                s.push('(');
            else
            {
                if(s.empty())
                {
                    mode=0;
                    break;
                }
                s.pop();
            }
        }
        if(s.empty()&&mode==1)
            printf("YES\n");
        else
            printf("NO\n");
        mode=1;
        s={};
   }
}
