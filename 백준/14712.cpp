/*
문제 :넴모넴모 (Easy)
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : 처음에 완탐으로 풀려고 햇다. 그래서 모든 경우에 넴모인 경우를 빼고 set에 넣어서 크기를 구하려고 햇다.
이러니까 시간초과가 난다. 그래서 답을 봣다....
약간 문제를 잘 못이해한게 그냥 넴모의 경우를 돌지 않으면 된다. 이 생각을 못한게 아쉽다. 그래서 넴모인 경우 재귀를 돌지 않게 하니 경우의수가 적게 나온듯 하다.
먼가 비트마스킹쓰면 좀 더 빨리 풀거 같긴한데 일단 생각이 안나니 추후에 풀겟다.
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

vector<vector<int>> arr(26,vector<int>(26));
int n, m;
int ans = 0;

void dfs(int depth) 
{
    int y = depth / m;
    int x = depth % m;

    if (depth == n * m)
    {
        ans++;
        return;
    }
    arr[y][x] = 1;
    if (!(y>0&&x>0&& arr[y][x -1] == 1 && arr[y - 1][x] == 1 && arr[y - 1][x - 1] == 1))
    {
        dfs(depth + 1);
    }
    arr[depth / m][depth % m] = 0;
    dfs(depth + 1);
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    dfs(0);

    cout << ans;
}
