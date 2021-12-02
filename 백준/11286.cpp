#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    
    int n;
    int now;
    priority_queue<int> pq;//음수
    priority_queue<int, vector<int>, greater<int>> pq2;//양수
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        
        if(now==0)
        {
            if(pq.empty()&&pq2.empty())
            {
                printf("0\n");
            }
            else if(pq.empty())
            {
                printf("%d\n",pq2.top());
                pq2.pop();
            }
            else if(pq2.empty())
            {
                printf("%d\n",pq.top());
                pq.pop();
            }
            else
            {
                if(abs(pq.top())>abs(pq2.top()))
                {
                    printf("%d\n",pq2.top());
                    pq2.pop();
                }
                else
                {
                    printf("%d\n",pq.top());
                    pq.pop();
                }
            }
            
        }
        else
        {
            if(now>0)
                pq2.push(now);
            else
                pq.push(now);
        }
    }  
}
