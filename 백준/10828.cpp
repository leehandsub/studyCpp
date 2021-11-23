#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
   int n;
   stack <int> s;
   string find;
   int now;
   scanf("%d",&n);
   for(int i=0;i<n;i++)
   {
       cin>>find;
       if(find=="push")
       {
           scanf("%d",&now);
           s.push(now);
       }
       else if(find=="top")
       {
            if(s.empty())
                printf("-1\n");
            else
            {
                printf("%d\n",s.top());
            }
       }
       else if(find=="size")
       {
           cout<<s.size()<<"\n";
       }
       else if(find=="empty")
       {
           printf("%d\n",s.empty());
       }
       else
       {
            if(s.empty())
                printf("-1\n");
            else
            {
                printf("%d\n",s.top());
                s.pop();
            }
       }
   }
   
}
