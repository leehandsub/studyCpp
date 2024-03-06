/*
문제 :제곱수의 합
시간 :60분
ide 활용 : o
질문 보기 : o
피드백 : 음... 처음에는 그리디하게 풀라다가 18이라는 반례 찾고 완탐으로 할려니 시간초과가 낫다.
그래서 딱봐도 dp겠구나 생각햇는데 어떻게 구현해야지?라는 생각이 들어서 답을 봣다...
1로만 더해서 i값을 만든다면 경우의 수는 i가 될 것이다. -> 아 이래서 dp[i] =i로 초기화햇구나.. 
예를 들어, dp[5]의 경우
dp[5]=dp[5-1*1]+1 (dp[4]인 경우에 1을 제곱한 값을 더한 경우)
dp[5]=dp[5-2*2]+1 (dp[1]인 경우에 2를 제곱한 값을 더한 경우)
코드를 봐도 이해가 안돼서 설명을 들으니 이해가 됏다. dp는 역시 너무 어렵다...
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

    int n;
    cin >> n;

    vector<int> dp(n + 1,1000000);
    for (int i = 1; i < 350; i++)
    {
        if (i * i > n )
            break;
        dp[i*i] = 1;
    }
    
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    cout << dp[n];
}
    
