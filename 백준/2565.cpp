/*
문제 :전깃줄
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : 어떻게 풀어야하는지 감이 아예 안왓다.요즘 문제가 역뱡향으로 생각하기가 많은거 같다.
일단 왼쪽으로 오름차순해서 오른쪽 나온 값이 있으면 거기서 최대 증가수열이 제일 연결가능한 전깃줄이다.
거기서 n을 빼면 답이 나온다. LIS라고 하는데 지금은 N^2풀엇지만 이분탐색으로 구하는 방버이 있다하니 정리해보야겟다.
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
    int a, b;
    vector<pair<int, int>> arr;
    vector<int> dp(501,1);

    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr.push_back({ a,b });
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i].second>arr[j].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << n - *max_element(dp.begin(), dp.end());

}
