#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int now=2;
    int total = brown+yellow;
    while(1)
    {
        if(total%now==0)
        {
            if(now*2+(total/now-2)*2==brown)
            {
                answer.push_back(total/now);
                answer.push_back(now);
                break;
            }
        }
        now++;
    }
    
    return answer;
}
