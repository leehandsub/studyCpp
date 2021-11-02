#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main(void) {
    
    set<string> s;
    string now;
    int n,m;
    int size=0;
    int cnt=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        cin>>now;
        s.insert(now);
    }
    size=s.size();
    for(int i=0;i<m;i++)
    {
        cin>>now;
        s.insert(now);
        if(s.size()!=size)
        {
            s.erase(s.find(now));
        }
        else
            cnt++;
        
    }
    printf("%d",cnt);
}
