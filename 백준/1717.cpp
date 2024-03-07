/*
문제 :집합의 표현
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : 처음에는 set써서 할려고 햇는데 음? 먼가 재귀로 하면 될거 같아서 생각했지만 감이 안잡혀서 답을 봣다
대표적인 union-find 문제다 나중에. 제대로 공부해서 내껄로 만들어야겟다. 100만인데 10만이라고 착가해서 좀 많이 틀렷다.
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

int arr[1000001];

int union_find(int now)
{
    if (arr[now] == now)
        return now;
    return arr[now] = union_find(arr[now]);
}

void merge(int a,int b)
{
    int start = union_find(a);
    int end = union_find(b);

    if (start == end) return;
        arr[end] = start;
}


int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n,m;
    cin >> n>> m;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    int select, a, b;
    while (m--)
    {
        cin >> select >> a >> b;
        if (select == 0)//합
        {
            merge(a, b);
        }
        else
        {
            int x = union_find(a);
            int y = union_find(b);
            if (x == y)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    
}
    
