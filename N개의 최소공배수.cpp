#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    int now=2;
    int index=-1;
    sort(arr.begin(),arr.end());
    int max=arr[arr.size()-1];
    int flag=0;
    while(1)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]%now==0)
            {
                flag++;
                if(flag==1)
                {
                    index=i;
                }
                if(flag==2)
                {
                    arr[index]/=now;
                    arr[i]/=now;
                    answer*=now;
                }
                if(flag>2)
                {
                    arr[i]/=now;
                }
            }
        }
        if(flag==0||flag==1)
            now++;
        flag=0;
        if(now>max)
            break;
    }
    for(int i=0;i<arr.size();i++)
    {
        answer*=arr[i];
    }
    
    return answer;
}
