/*
문제 :극장 좌석
시간 :40분
ide 활용 : x
질문 보기 : o
피드백 : dp느낌은 낫긴햇는데 음 머지...라고 생각햇다. 그래서 답을 보고 구현을 햇다.
각 vip 사이의 경우의 수를 곱해주면 되는 문제이다. 먼가 진득하게 생각햇으면 풀엇을같은데 요즘 문제푸는데 집중이 안되긴한다.
매우 큰일난 부분... ㅋㅋㅋㅋ
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
    
    int n,m;
    int ans = 1;
    cin >> n >> m;

    vector<int> arr(n + 1);
    vector<int> pibo;
    pibo.push_back(1);
    pibo.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        pibo.push_back(pibo[i - 1] + pibo[i - 2]);
    }
    
    
    int num;
    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        ans *= pibo[num - idx - 1];
        idx = num;
    }
    ans *= pibo[n - idx];
    cout << ans;
}
