/*
문제 :행운의 문자열 
시간 :30분
ide 활용 : x
질문 보기 : x
피드백 : 그냥 순열 문제이다. 첨에 dfs 짤라 햇는데 안되서 라이브러리를 사용했다.
음 재귀로 우예짜노 ㅋㅋㅋㅋㅋㅋ
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

string s;
int ans = 0;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    string now;

    cin >> s;
    sort(s.begin(), s.end());
    do {
        int flag = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                flag = 1;
                break;
            }
        }
        if(flag==0)
            ans++;

    } while (next_permutation(s.begin(), s.end()));

    cout << ans;

}
