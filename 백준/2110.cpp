/*
문제 :공유기 설치
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : 첨에는 모든 한개씩 차이를 구해서 하나 넣을때마다 priority_queue같은데 넣어서 구해야하나 싶어서고민을 했지만
혹시 같을 때 어떤것을 넣느냐에 따라 미래가 달라진다고 생각해서 일단 풀이를 봣다.
음 이분탐색 이었군... 2개의 차이중 제일 큰것은->평균이 계쏙 높게 해서 찾아라인 것을 첨 알았다.
right를 이상하게 줘서 조금 많이 틀렷다.ㅜ
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

int n, c;

bool check_install(vector<int> result,int now)
{
    int i = 0;
    int num = 0;
    int j = 1;
    while (j!=c)
    {
        num += result[i++];
        if (num >= now)
        {
            num = 0;
            j++;
        }
        if (i == result.size())
            break;
    }
    if (j == c)
        return true;
    else
        return false;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int ans = 0;

    cin >> n >> c;

    vector<int> arr(n);
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++)
    {
        result.push_back(arr[i] - arr[i - 1]);
    }
    
    int left = 0;
    int right = arr[n-1];
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (check_install(result, mid))
        {
            left = mid + 1;
            ans = max(ans,mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << ans;

}
