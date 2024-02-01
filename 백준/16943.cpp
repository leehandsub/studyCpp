/*
문제 :숫자 재배치
시간 :10분
ide 활용 : x
질문 보기 : x
피드백 : 그냥 순열 문제이다. 끝이다...
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int A, b;

    cin >> A >> b;

    string a = to_string(A);
    int ans = -1;

    sort(a.begin(), a.end());
    
    do {
        string now;
        for (int i = 0; i < a.size(); i++)
        {
            now.push_back(a[i]);
        }
        if (a[0] == '0')
            continue;

        if (stoi(now) < b)
        {
            ans = max(ans, stoi(now));
        }


    } while (next_permutation(a.begin(), a.end()));

    cout << ans;
}
