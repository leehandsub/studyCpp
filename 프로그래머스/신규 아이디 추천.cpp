/*

문제 : 프로그래머스 lv 1 신규 아이디 추천
시간 : 40분
ide 활용 : o
질문 보기 : o
피드백 : 그냥 단순 문자열 구현 
........과 같은 예외를 생각 못함 
처음에는 ...을 한번에 없애려고 했는데 하나씩 없애도록 해야 잘된다.

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

string solution(string new_id) {
    string answer = "";
    int find = 0;
    char temp;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = new_id[i] - 'A' + 'a';
        }
        else if ((new_id[i] < 'a' || new_id[i]>'z') &&
            (new_id[i] < '0' || new_id[i]>'9') &&
            new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.')
        {
            new_id.erase(i, 1);
            i--;
        }
    }
    for (int i = 0; i < new_id.size() - 1; i++)
    {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
        {
            new_id.erase(i, 1);
            i--;
        }
    }
    if (new_id[0] == '.')//4
        new_id.erase(0, 1);
    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();
    if (new_id.size() == 0)//5
        new_id.push_back('a');
    if (new_id.size() > 15)//6
    {
        for (int i = new_id.size() - 1; i >= 15; i--)
            new_id.pop_back();
    }
    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();
    if (new_id.size() <= 2)//7
    {
        temp = new_id[new_id.size() - 1];
        while (1)
        {
            if (new_id.size() >= 3)
                break;
            new_id.push_back(temp);
        }
    }
    return new_id;
}
