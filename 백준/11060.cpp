/*
문제 : 점프 점프
시간 : 10분
ide 활용 : x
질문 보기 : x
피드백 : 사실 n이 작아서 dfs로 풀어도 될거 같은데 일단 dp로 풀엇다.
근데 어차피 n*m이라 좀 커지면 못할지도?
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
#include <cstdio>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int num;
    vector<int> dp(n,1999999999);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        arr[i] = num;
    }
    dp[0] = 0;
    for (int j = 1; j <= arr[0]; j++)
    {
        if (j >= n)
            break;
        dp[j] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i+1; j <= i+arr[i]; j++)
        {
            if (j >= n)
                break;

            dp[j] = min(dp[i] + 1, dp[j]);

        }
    }
    if (dp[n - 1] == 1999999999)
        cout << -1;
    else
        cout << dp[n - 1];
}
