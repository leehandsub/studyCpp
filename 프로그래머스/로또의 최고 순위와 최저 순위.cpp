#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int win=0;
    int now=0;
    for(int i=0;i<6;i++)
    {
        if(lottos[i]==0)
        {
            now++;
            continue;
        }
        for(int j=0;j<6;j++)
        {
            if(lottos[i]==win_nums[j])
                win++;
        }
    }
    if(6-win-now+1>6)
        answer.push_back(6);
    else    
        answer.push_back(6-win-now+1);
    if(6-win+1>6)
        answer.push_back(6);
    else
        answer.push_back(6-win+1);
    
    return answer;
}
