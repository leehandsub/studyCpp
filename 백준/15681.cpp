/*
문제 :트리와 쿼리
시간 :40분
ide 활용 : x
질문 보기 : o
피드백 : 사실 문제에서 어떻게 풀라는지 나온다. 그거보고 문제 풀엇다.
한번 다시 읽어볼만할지도? 트리에 대해 잘 설명해준다.
root를 안주는 줄 알고 최초것을 루트로 풀어서 한번 틀렷다.... 문제를 잘읽자
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

vector<int> vit;
vector<vector<int>> arr;
void dfs(int now) 
{
    vit[now] = 1;
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i]] == 0)
        {
            dfs(arr[now][i]);   
            vit[now] += vit[arr[now][i]];
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n, r, q;    
    cin >> n >> r >> q;
    arr = vector<vector<int>>(n + 1, vector<int>());
    vit = vector<int>(n + 1);
    int a, b;
    int now;
    for (int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(r);
    for (int i = 0; i < q; i++)
    {
        cin >> now;
        /*if (vit[now] == 0)
        {
            dfs(now);
        }*/
        cout << vit[now]<<"\n";
    }

}
    
