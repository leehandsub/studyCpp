/*
���� : ���α׷��ӽ� lv 2 ���ڿ� ����
�ð� : 50��
ide Ȱ�� : o
���� ���� : o
�ǵ�� : ���ڿ��� 1�ϰ�츦 ���� ������ �f��..
���ڿ� ���̺��� ���ͷ� ���� ������ �ߴ�.
������ for���� ���������� �����ؾ��ߴ�.
ide���п� Ǯ���µ� ������ ��Ǯ����?
�̰Ϳ� ���� ������ �� �غ����Ѵ�.
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