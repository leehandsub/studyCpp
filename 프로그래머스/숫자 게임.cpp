#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int i=0,j=0;
    int min=0,max=0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    while(i<A.size()&&j<B.size())
    {
        if(A[i]<B[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    return i;
}
