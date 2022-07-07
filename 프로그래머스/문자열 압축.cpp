/*
문제 : 프로그래머스 lv 2 문자열 압축
시간 : 50분
ide 활용 : o
질문 보기 : o
피드백 : 문자열이 1일경우를 몰라서 질문을 봣다..
문자열 길이별로 벡터로 만들어서 압축을 했다.
마지막 for문이 끝낫을때를 생각해야했다.
ide덕분에 풀엇는데 없으면 못풀지도?
이것에 대한 생각을 좀 해봐야한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 999999999;
    string now;
    vector<string> temp;
    string ans;
    int find = 1;

    for (int i = 1; i <= s.size() / 2; i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            now.push_back(s[j]);
            if ((j + 1) % i == 0)
            {
                temp.push_back(now);
                now = "";
            }
        }
        if (now.size() != 0)
            temp.push_back(now);
        now = temp[0];
        for (int j = 1; j < temp.size(); j++)
        {
            if (temp[j] == now)
            {
                find++;
            }
            else
            {
                if (find > 1)
                    ans += to_string(find);
                ans += now;
                now = temp[j];
                find = 1;
            }
        }
        if (find > 1)
            ans += to_string(find);
        ans += now;
        find = 1;
        if (answer > ans.size())
            answer = ans.size();
        find = 1;
        now = "";
        ans = "";
        temp.clear();
    }
    if (answer == 999999999)
        answer = 1;
    return answer;
}

int main(void)
{
    if (solution("a") == 1)
        printf("true");
    else
        printf("flase");
}