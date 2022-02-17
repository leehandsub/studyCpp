#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int num;

bool compare(const string a,const string b)
{
    if(a[num]!=b[num])
    {
        return a[num]<b[num];
    }
    else
        return a < b;
}//compare을 처음으로 이렇게 써봤다. 

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    num=n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}
