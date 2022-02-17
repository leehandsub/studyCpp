#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector <int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    for(int i=3;i<=n;i++)
    {
        a.push_back(a[i-2]%1234567+a[i-1]%1234567);
    }
    
    return a[n]%1234567;
}
