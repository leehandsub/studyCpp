#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>

using namespace std;

int main(void){
    
    string s="";
    int now;
    stack<int> st;
    int mode=1;
    int n;
    int find;
    int j=1;
    st.push(0);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&now);
        while(1)
        {
            if(st.top()==now)
            {
                st.pop();
                s+="-";
                break;
            }
            else 
            {
                if(j>now)
                {
                    printf("NO");
                    return 0;
                }
                st.push(j);
                j++;
                s+="+";
            }
        }
    }
    for(int i=0;i<s.size();i++)
    {
        printf("%c\n",s[i]);
    }
    
}
