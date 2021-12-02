#include <string>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;


int main(void)
{
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    int now;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&now);
            
            pq.push(now);
            if(pq.size()>n)
                pq.pop();
        }
    }

    printf("%d", pq.top());
}
