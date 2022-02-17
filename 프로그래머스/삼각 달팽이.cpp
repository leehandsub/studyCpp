#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> arr(n+1,vector<int>(n+1,0));
    int i=0,j=0;
    int mode=1;
    int now=1;
    while(now<=n*(n+1)/2)
    {
        
        if(i<n&&j<n&&i>=0&&j>=0&&arr[i][j]==0)
        {
            arr[i][j]=now;
            now++;
        }
        else
        {
            if(mode==1)
            {
                i--;
                mode=2;
            }
            else if(mode==2)
            {
                j--;
                mode=3;
            }
            else
            {
                j++;
                i++;
                mode=1;
            }
        }
        if(mode==1)
        {
            i++;
        }
        else if(mode==2)
        {
            j++;
        }
        else
        {
            i--;
            j--;
        }
    }  
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}
