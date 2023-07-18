/*
문제 : 문자열 게임 2
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 길이가 k가 될때마다 최대 최소를 각 알파벳 별로 계산하게 햇다.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    string s;
    int k;

    cin >> T;

    while (T--)
    {
        vector<int> minCnt(27, 1999999999);
        vector<int> maxCnt(27, 0);
        vector<vector<int>> index(27);
        cin >> s;
        cin >> k;

        for (int i = 0;i < s.size();i++)
        {
            int ind = s[i] - 'a';
            index[ind].push_back(i);
            if (index[ind].size() == k)
            {
                int size = index[ind][k - 1] - index[ind][0]+1;
                minCnt[ind] = min(minCnt[ind], size);
                maxCnt[ind] = max(maxCnt[ind], size);
                index[ind].erase(index[ind].begin());
            }
        }

        int maxAns = *max_element(maxCnt.begin(), maxCnt.end());
        int minAns = *min_element(minCnt.begin(), minCnt.end());

        if (maxAns == 0)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << minAns << " " << maxAns << "\n";
        }
    }

}

