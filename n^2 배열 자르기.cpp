#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int now=0;
    int find=0;
    for(int i=left+1;i<=right+1;i++)
    {
        now=i/n+1;
        find=i%n;
        if(find==0)
        {
            answer.push_back(n);
        }
        else if(now>=find)
            answer.push_back(now);
        else
            answer.push_back(find);
        
    }
    
    return answer;
}
