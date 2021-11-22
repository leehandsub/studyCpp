#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;
int main(void)
{
    string in,out;
    int n,j=0;
    int cnt=0;
    int k=0;
    set<char> s;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        cin>>in;
        while(in[j]!='\0')
        {
            if(s.count(in[j])==0)
            {
                s.insert(in[j]);
                k=j+1;
                while(1)
                {
                    if(in[k]!=in[j])
                        break;
                    k++;
                }
                j=k-1;
            }
            else
                break;
            
            j++;
        }
        if(j==in.size())
            cnt++;
        s.clear();
        j=0;
    }
   
   printf("%d",cnt); 
}
