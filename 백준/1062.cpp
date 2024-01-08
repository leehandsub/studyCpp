/*
문제 : 가르침
시간 : 40분
ide 활용 : o
질문 보기 : 
피드백 : 단순 구현이다.
a,n,t,i,c를 제외시키고 문제를 풀었다. 조합을 활용하여 경우의 수마다 완탐을 돌며 최대 단어를 찾도록
노려하였다. 먼가 시간이 오래걸려서 조금 더 빨리 푸는 방법을 찾긴 해야할지도>?
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
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

//n,a,t,i,c 

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;
    vector<string> arr;



    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        sort(s.begin(), s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        string ts;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'a' || s[j] == 'n' || s[j] == 't' || s[j] == 'i' || s[j] == 'c')
                continue;
            ts.push_back(s[j]);
        }
        arr.push_back(ts);

    }
    if (k < 5)
    {
        cout << 0;
        return 0;
    }
    vector<char> al;

    for (int i = 0; i < 26; i++)
    {
        if (i == 0 || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a' || i == 'c' - 'a')
            continue;
        al.push_back('a' + i);
    }

    vector<bool> temp(21, false);
    for (int i = 0; i < k - 5; i++)
    {
        temp[i] = true;
    }
    int ans = 0;

    do {
        vector<char> ch;
        for (int i = 0; i < al.size(); i++)
        {
            if (temp[i])
            {
                ch.push_back(al[i]);
            }
        }
        int ma = 0;
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < arr[i].size(); j++)
            {
                for (int k = 0; k < ch.size(); k++)
                {
                    if (arr[i][j] == ch[k])
                    {
                        cnt++;
                        break;
                    }
                }
            }

            if (cnt == arr[i].size())
            {
                ma++;
            }
        }

        ans = max(ma, ans);

    } while (prev_permutation(temp.begin(), temp.end()));


    cout << ans;
}
