/*
문제 :합분해 
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : dp푼다는 접근자체는 잘햇는데 0으로 시작하는지 몰랏다 ㅋㅋㅋㅋㅋㅋㅋ
그래서 아니 이게 어떻게 해야하지 생각햇는데 답을 보니 0도 포함한 숫자이더라
아 문제 계속 잘 읽어야하는데 큰일이다.
그리고 k까지해야하는데 n까지 해도 되는줄 알고 정말 많이 틀렷다 ㅜ
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

int dp[201][201];//i를 만들기 위한 j의 갯수의 경우의수

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    

    int n, k;

    cin >> n >> k;

    for (int i = 0;i <= k; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%1000000000;
        }
    }

    cout << dp[n][k];
}
