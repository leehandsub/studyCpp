#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
   int n;
   queue <int> q;
   string now;
   int num;
   
   scanf("%d",&n);
   
   for(int i=0;i<n;i++)
   {
       q.push(i+1);
   }
   while(q.size()!=1)
   {
       q.pop();
        num=q.front();
        q.pop();
        q.push(num);
   }
   printf("%d",q.front());

}
