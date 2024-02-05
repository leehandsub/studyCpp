/*
문제 :맥주 마시면서 걸어가기
시간 :30분
ide 활용 : o
질문 보기 : o
피드백 : 먼가 완탐하면 풀 수 있을거 같은데 bfs로 하기에는 vit하는게 어려울 거 같고 dfs는 그냥 100^100인거 같아서
어떻게 풀지 하고 답을 봣다. 그냥 bfs네 그냥 vit체크 잘하면 되네??? 머지 
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

int start_x;
int start_y;
int end_x;
int end_y;
int n;
bool bfs(vector<pair<int, int>> arr)
{
    queue<pair<int, int>> q;
    vector<int> vit(n);

    q.push({ start_x,start_y });
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (abs(end_x - x)+abs( end_y - y)<=1000)
        {
            return true;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (vit[i] == 1)
                continue;
            if (abs(x - arr[i].first) + abs(y - arr[i].second) <= 1000)
            {
                q.push({ arr[i].first,arr[i].second });
                vit[i] = 1;
            }
        }
    }
    return false;
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

        int a, b;

        vector<pair<int, int>> arr;
        cin >> start_x >> start_y;

        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            arr.push_back({ a,b });
        }

        cin >> end_x >> end_y;
        if (bfs(arr))
            cout << "happy"<< "\n";
        else
            cout << "sad" << "\n";
    }
}
