/*
문제 :숫자고르기
시간 :60분
ide 활용 : o
질문 보기 : x
피드백 : 처음에 풀었을 때는 사이클만 찾는다는 것은 알았지만 어떻게 구현해야할지 몰라서 새맘 새뜻으로 다시 풀었다.
그러니 잘 풀렷고 구현 실력을 조금 더 올리자...
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

vector<int> arr;
vector<int> ans;

void dfs(int start,int now,vector<int> vit) 
{
    if (now == start)
    {
        for (int i = 1; i < vit.size(); i++)
        {
            if (vit[i] == 1)
                ans.push_back(i);
        }
        return;
    }
    if (vit[now] == 1)
        return;
    vit[now] = 1;
    dfs(start, arr[now],vit);
}


int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    arr.push_back(-1);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int now;
        cin >> now;
        arr.push_back(now);
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> vit(n + 1);
        vit[i] = 1;
        dfs(i,arr[i], vit);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }

}
    
