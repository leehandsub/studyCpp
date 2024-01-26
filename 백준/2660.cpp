/*
문제 : 회장뽑기
시간 : 1시간
ide 활용 : x
질문 보기 : x
피드백 : 그냥 bfs로 풀었다. 인접행렬 만들어서 모든 level찾아서 그중 최솟값을 뽑아줫다.
플로이드 워셜도 쓰라고 하던데 음 언젠가 연습해야지 ㅋㅋㅋㅋㅋ
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

    int a, b;

    vector <vector<int>> arr(n+1,vector<int>());
    vector<int> ans(n + 1);

    while (1)
    {
        cin >> a >> b;
        if (a == -1 && b == -1)
            break;

        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i < n + 1; i++)
    {
        queue<pair<int, int>> q;
        q.push({ i,0 });
        vector<int> levels(n + 1,-1);
        levels[i] = 0;

        while (!q.empty())
        {
            int now = q.front().first;
            int level = q.front().second;
            q.pop();

            for (int j = 0; j < arr[now].size(); j++)
            {
                int next = arr[now][j];

                if (levels[next] != -1)
                    continue;

                q.push({ next,level + 1 });
                levels[next] = level + 1;
            }
        }
        ans[i] = *max_element(levels.begin(), levels.end());
    }

    int ans_size = *min_element(ans.begin() + 1, ans.end());

    vector<int> temp;

    for (int i = 0; i < ans.size(); i++)
    {
        if (ans_size == ans[i])
        {
            temp.push_back(i);
        }
    }
    cout << ans_size << " " << temp.size()<<"\n";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

}
