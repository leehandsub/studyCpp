/*
문제 : 교수가 된 현우
시간 : 10분
ide 활용 : x
질문 보기 : x
피드백 : 2는 많을테니 5의 갯수를 열심히 찾았다.
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;

    int N;
    vector<int> arr;
    
    cin >> T;

    for (int i = 0;i < T;i++)
    {
        cin >> N;
        int num = 5;
        long long answer = 0;
        while (1)
        {
            answer += (N/ num);
            if (N < num)
                break; 
            num *= 5;
        }
        cout << answer<<"\n";
    }
}
