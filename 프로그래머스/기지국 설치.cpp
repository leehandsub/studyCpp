/*#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int k=1;
    int now=0;
    int find=2*w+1;
    vector<int> arr(n+1,0);

    for(int i=0;i<stations.size();i++)
    {
        for(int j=stations[i]-w;j<=stations[i]+w;j++)
        {
            if(j<0)
                continue;
            if(j>n)
                break;
            arr[j]=1;
        }
    }//처음 작업
    while(k<=n)
    {
        if(arr[k]==0)
        {
            answer++;
            k+=find;
        }
        if(arr[k]==1)
        {
            k++;
        }
    }
    
    return answer;
}//처음 생각한 방법 효율성 박살남... 그래서 인덱스로만 계산해봄*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int k=1;
    int now=0;
    int i=0,j=1;
    int find=2*w+1;
    while(j<=n)
    {
        if(stations[i]-w<=j&&i<stations.size())
        {
            j=stations[i]+w+1;
            i++;
            continue;
        }
        j+=find;
        answer++;
    }
    return answer;
}
