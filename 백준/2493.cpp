/*
문제 :탑
시간 :40분
ide 활용 : o
질문 보기 : o
피드백 : 음 투포인터로 풀어야하나 이분탐색인가 고민을 햇지만 n^2의 경우의수 아니면 너무 어렵게 풀어야하는데 생각빢에 안나서
힌트를 봣다 스택?! 아 좋은게 있엇군 하고 바로 문제풀이하고 금방 풀었다 index 1부터 시작이라 그거 잡는데 조금 걸렷다. 스택, q 자료구조 기본활용 다시 
풀어야할지도?
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
    vector<int> arr(n);
    vector<int> ans(n);
    stack<pair<int,int>> st;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    st.push({ arr[0],1 });
    for (int i = 1; i < n; i++)
    {
        while (!st.empty())
        {
            if (st.top().first > arr[i])
            {
                ans[i] = st.top().second;
                break;
            }
            st.pop();
        }
        st.push({ arr[i],i+1 });
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
