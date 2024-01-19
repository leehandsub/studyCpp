/*
문제 : 두 용액
시간 : 1시간 30분
ide 활용 : o
질문 보기 : o
피드백 : 접근자체는 잘햇다. 이분탐색으로 경우의 수 모두 찾기
근데 20억 넘을때 처리를 안해서 틀렷다.... 이제 19999999999 못쓰겟다. ㅋㅋㅋ
암튼 질문 게시판으로 로직 수정하니 잘 됏다.
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

    vector<int> pl;
    vector<int> mi2;
    int ansNum = 2000000010;//최대 일때 오류네...
    int ans1 = 0;
    int ans2 = 0;
    int n;

    cin >> n;

    int num;
    for (int i = 0; i < n; i ++ )
    {
        cin >> num;
        if (num > 0)
        {
            pl.push_back(num);
        }
        else
        {
            mi2.push_back(-num);
        }
    }
    //mi2 = mi;

    sort(pl.begin(), pl.end());
    sort(mi2.begin(), mi2.end());

    if (pl.size() >= 2)
    {
        ans1 = pl[0];
        ans2 = pl[1];
        ansNum = min(ansNum, abs(ans1 + ans2));
    }

    if (mi2.size() >= 2)
    {
        if (ansNum > abs(mi2[0] + mi2[1]))
        {
            ans1 = -mi2[0];
            ans2 = -mi2[1];
            ansNum = abs(mi2[0] + mi2[1]);
        }
    }

    for (int i = 0; i < pl.size(); i++)
    {
        int now = pl[i];
        int temp2 = lower_bound(mi2.begin(), mi2.end(), now) - mi2.begin();

        if (temp2 != 0)
        {
            if (ansNum > abs(now - mi2[temp2-1]))
            {
                ans1 = now;
                ans2 = -mi2[temp2-1];
                ansNum = abs(ans1 + ans2);
            }
        }

        if (temp2 != mi2.size())
        {
            if (ansNum > abs(now - mi2[temp2]))
            {
                ans1 = now;
                ans2 = -mi2[temp2];
                ansNum = abs(ans1 + ans2);
            }
        }
    }

    cout << min(ans1,ans2)<<" " << max(ans1, ans2);
    
}
