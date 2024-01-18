/*
문제 : 전화번호 목록
시간 : 40분
ide 활용 : x
질문 보기 : o
피드백 : 먼가 kmp 같기도 하고 좋은 자료구조 쓰면 풀릴거 같긴한데
잘 생각이 안나서 힌트를 봣다. hash로 푸는 것을 확인햇다.
문자열 한개씩 확인하며 혹시 hash에 있으면 false 없으면 true를 출력하게 햇다.
보니까 트라이라는 자료구조를 써도 되던데 나중에 공부해봐야겟다.
substr로 어차피 소팅하면 다음꺼만 비교하면 되는것을 비교하는 것도 있더라....
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

int n;

bool is_con(vector<string> arr) 
{
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string temp;
        for (int j = 0; j < arr[i].size(); j++)
        {
            temp.push_back(arr[i][j]);
            if (m.count(temp) == 1)
            {
                return false;
            }
        }
        m.insert({ temp,1 });
    }
    return true;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<string> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        
        if (is_con(arr))
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
}
