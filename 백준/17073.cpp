/*
문제 :나무 위의 빗물
시간 :60분
ide 활용 : o
질문 보기 : o
피드백 : 처음에 접근을 그냥 w/leaf노드 갯수로 햇는데 틀렷다 나오길래
내가 직접 다 계산해줫다. 그래도 틀리길래 음 머지 하고 보니까 어느 숫자가 넘어가면 0.00000이 아닌 0.0e^32머 이런식으로 
나와서 틀린것이다. 그래서 printf로 자릿수를 정해주니 맞앗다...
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

vector<vector<int>> arr;
vector<double> vit;
vector<int> leaf;

void dfs(int now)
{
    if (now == 1 && arr[now].size() == 0)
    {
        leaf.push_back(now);
        return;
    }

    if (arr[now].size() == 1&&now!=1)
    {
        leaf.push_back(now);
        return;
    }
    for (int i = 0; i < arr[now].size(); i++)
    {
        if (vit[arr[now][i]] == 0)
        {
            if (now == 1)
            {
                vit[arr[now][i]] = vit[now] / ((double)arr[now].size());
            }
            else
                vit[arr[now][i]] = vit[now] / ((double)arr[now].size() - 1);
            dfs(arr[now][i]);
        }
    }
}
int main(void)
{
    /*cin.tie(0);
    cout.tie(0);*
    ios_base::sync_with_stdio(false);*/
    

    int n;
    double w;
    cin >> n >> w;
    
    arr = vector<vector<int>>(n+1, vector<int>());
    vit = vector<double>(n + 1);

 
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    vit[1] = w;
    dfs(1);
    double sum = 0;
    for (int i = 0; i < leaf.size(); i++)
    {
        sum += vit[leaf[i]];
    }


    printf("%f", sum / leaf.size());

}
    
