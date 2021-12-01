#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    
    int n;
    int now;
    priority_queue<int> pq;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&now);
        
        if(now==0)
        {
            if(pq.empty())
                printf("%d\n",now);
            else
            {
                printf("%d\n",pq.top());
                pq.pop();
            }
        }
        else
            pq.push(now);
    }    
}
