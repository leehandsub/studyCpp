#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int l=0;
    int k=0;
    int find=1;
    for(int i=0;i<skill_trees.size();i++)
    {
        for(int j=0;j<skill_trees[i].size();j++)
        {
            for(k=l;k<skill.size();k++)
            {
                if(skill_trees[i][j]==skill[k])
                {
                    if(k!=l)
                    {
                        find=0;
                    }
                    if(k==l)
                        l++;
                    break;
                }   
            }
            if(find==0)
                break;
            
        }
        if(find==1)
            answer++;
        find=1;
        l=0;
    }
    
    return answer;
}
