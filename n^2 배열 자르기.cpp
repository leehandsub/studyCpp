#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    long long now=0;
    long long find=0;//걍 다 int를 longlong으로 바꾸니 해결됨... 개같네요
    for(long long i=left+1;i<=right+1;i++)
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
