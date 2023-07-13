/*
문제 : IF문 좀 대신 써줘
시간 : 10분
ide 활용 : x
질문 보기 : x
피드백 : 그냥 lower_bound사용하면 쉬운 문제였다.

*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    string s;
    int num;
    map<int, string> m;
    vector<int> arr;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> s >> num;
        m[i] = s;
        arr.push_back(num);
    }

    for (int i = 0; i < M; i++)
    {
        cin >> num;
        cout << m[lower_bound(arr.begin(), arr.end(),num)-arr.begin()]<<"\n";
    }

}
