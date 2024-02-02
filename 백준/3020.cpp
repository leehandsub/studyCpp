/*
문제 :개똥벌레
시간 :60분
ide 활용 : o
질문 보기 : o
피드백 : 음 처음에는 이분탐색으로 최솟값을 찾을려고 햇다. 그런데 아무리 생각해도 아닌거 같아
답을 봣는데 먼저 up, down을 나누고 거기서 각 높이마다 갯수를 이분탐색으로 구하고 거기서 최솟값을 구하게 햇다.
답을 보니 구현은 어렵지 않았다....
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
        
    int n, h;


    cin >> n >> h;
    vector<int> up;
    vector<int> down;
    vector<int> arr;
    int cnt_ans = 0;
    int num;
    int ans = 2099999999;
    int u=0, d=0;


    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (i % 2 == 0)
        {
            down.push_back(num);
        }
        else
        {
            up.push_back(num);
        }
    }

    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    for (int i = 1; i <= h; i++)
    {
        d = down.size()-(lower_bound(down.begin(), down.end(), i)-down.begin());
        u = up.size() - (lower_bound(up.begin(), up.end(), h - i+1) - up.begin());
        ans = min(ans, d + u);
        arr.push_back(d + u);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (ans == arr[i])
        {
            cnt_ans++;
        }
    }

    cout << ans << " " << cnt_ans;

}
