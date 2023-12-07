/*
문제 : 시리얼 번호
시간 : 20분
ide 활용 : o
질문 보기 : o
피드백 : 오래만에 알고리즘 해서 cmp을 어떻게 하는지 몰랏는데 잘돼서 다행이다.
string은 그냥 a<b로 비교해도 된다는 것을 첨으로 알았다.
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
#include <cstdio>

using namespace std;

int sToNum(string s)
{
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            num += s[i] - '0';
        }
    }
    return num;
}

bool cmp(string &a, string &b)
{
    if (a.size() == b.size())
    {
        if (sToNum(a) == sToNum(b))
        {
            return a < b;
        }
        return sToNum(a) < sToNum(b);
    }

    return a.size() < b.size();
}

int main(void)
{
    int n;
    cin >> n;
    string s;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}
