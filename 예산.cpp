#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int num=0;
    int i;
    sort(d.begin(),d.end());
    if(d[0]>budget)
        return 0;
        
    for(i=0;i<d.size();i++)
    {
        if(num>budget)
        {
            i=i-1;
            break;
        }
        else if(num==budget)
        {
            break;
        }
        num+=d[i];
    }
    return i;
}
