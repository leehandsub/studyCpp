/*
문제 : pr lv2 메뉴 리뉴얼
시간 : 60분
ide 활용 : o
질문 보기 : o
피드백 : 문제가 너무 띠용하다. 처음 읽고 나서 이해할수가 없음...
문제 이해하는데 시간을 많이 썻다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int now;
int mSize;
int vit[11];
int ans_cnt[11];
string s;
map<string, int> m;

void dfs(int idx, int cnt)
{
    if (cnt == now)
    {
        string find;
        for (int i = 0; i < mSize; i++)
        {
            if (vit[i] == 1)
            {
                find.push_back(s[i]);
            }
        }
        sort(find.begin(), find.end());
        if (m.count(find) == 0)
            m.insert(make_pair(find, 1));
        else
        {
            m[find]++;
            ans_cnt[find.size()] = max(ans_cnt[find.size()], m[find]);
        }
        return;
    }
    for (int i = idx; i < mSize; i++)
    {
        if (vit[i] == 1)
            continue;
        vit[i] = 1;
        dfs(i, cnt + 1);
        vit[i] = 0;
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++)
    {
        for (int j = 0; j < course.size(); j++)
        {
            s = orders[i];
            now = course[j];
            mSize = orders[i].size();
            if (mSize >= now)
                dfs(0, 0);

            for (int k = 0; k < mSize; k++)
            {
                vit[k] = 0;
            }

        }
    }
    auto iter = m.begin();
    for (int k = 0; k < m.size(); k++)
    {

        if(ans_cnt[iter->first.size()]==iter->second)
            answer.push_back(iter->first);
        
        iter++;
    }
    sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
    vector<string> ans = {"AC", "ACDE", "BCFG", "CDE"};

    vector<string> TEMP = solution({ "ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH" }, { 2, 3, 4 });

    if (ans == TEMP)
        printf("1");
    else
        printf("0");
}