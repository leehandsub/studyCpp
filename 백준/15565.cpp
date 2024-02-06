/*
문제 :귀여운 라이언
시간 :20분
ide 활용 : x
질문 보기 : x
피드백 : 기본적인 투포인터로 문제다
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
    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 1999999999;
    int cnt = 0;
    int i=0, j=0;
    while (i!=arr.size())
    {
        if (arr[i] == 1)
        {
            cnt++;
        }
        if (cnt == k)
        {
            cnt--;
            while (1)
            {
                if (arr[j++] == 1)
                {
                    ans = min(ans, i - j + 2);
                    break;
                }
            }
        }
        i++;
    }

    if (ans == 1999999999)
        cout << -1;
    else
        cout << ans;

}
