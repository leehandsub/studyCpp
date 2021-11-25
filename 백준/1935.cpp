#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>

using namespace std;

int arr[27];

int main(void){
    
    int n;
    string s;
    stack <double> st;
    double a,b;
    
    scanf("%d",&n);
    cin>>s;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<s.size();i++){
        if(s[i]-'A'>=0&&s[i]-'A'<=26)
        {
            st.push(arr[s[i]-'A']);
        }
        else
        {
            a=st.top();
            st.pop();
            b=st.top();
            st.pop();
            if(s[i]=='*')
            {
                st.push(b*a);
            }
            else if(s[i]=='+')
            {
                st.push(b+a);
            }
            else if(s[i]=='-')
            {
                st.push(b-a);
            }
            else
            {
                st.push(b/a);
            }
        }
    }
    printf("%.2lf",st.top());
    
}
