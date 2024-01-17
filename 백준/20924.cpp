/*
문제 : 트리의 기둥과 가지
시간 : 40분
ide 활용 : o
질문 보기 : o
피드백 : 완탐? dfs문제이다.
첨에는 방향그래프를 생각햇는데 
3 2
1 2 3
2 3 4
이 때 아 무방향 그래프로 생각해야하구나를 깨달았다 무방향 그래프에 따라 구현을 하다보니 시간이 오래 걸렷다.
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

struct NODE {
    int des;
    int cost;
    NODE(int _des, int _cost) {
        des = _des;
        cost = _cost;
    }
};

vector<vector<NODE>> arr;
int vit[200002];

int giga = 0;
int leaf = 0;

void leaf_dfs(int now,int co)
{
    int size = 0;
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i].des] == 0)
            size++;
    }
    if (size == 0)
    {
        leaf = max(leaf, co);
        return;
    }
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i].des] != 1)
        {
            vit[arr[now][i].des] = 1;
            leaf_dfs(arr[now][i].des, co + arr[now][i].cost);
            vit[arr[now][i].des] = 0;
        }
    }
}

void giga_dfs(int now)
{
    int size = 0;
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i].des] == 0)
            size++;
    }
    if (size > 1)
    {
        leaf_dfs(now,0);
        return;
    }
    if (size == 0)
    {
        return;
    }
    int idx = 0;
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i].des] == 0)
            idx = i;
    }
    giga += arr[now][idx].cost;
    vit[arr[now][idx].des] = 1;
    giga_dfs(arr[now][idx].des);
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    int start;
    int a, b, c;
    cin >> n>>start;

    vector<vector<NODE>> temp(n+1,vector<NODE>());

    arr = temp;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        arr[a].push_back(NODE(b, c));
        arr[b].push_back(NODE(a, c));
    }

    vit[start] = 1;
    giga_dfs(start);

    cout << giga << " " << leaf;
}
