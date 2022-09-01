/*
문제 : pr lv2 두 큐 합 같게 만들기
시간 : 10분
ide 활용 : x
질문 보기 : o
피드백 : 단순 구현이다. -1일 경우를 찾는데 질문을 봤다
처음에는 전체 사이즈까지만 확인하게 했는데 2배로 하니 정답이 됐다.
더 정확한 경우의 수가 있을지도?

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

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int now;
    long long s1 = 0, s2 = 0;
    queue<int> q1, q2;
    for (int i = 0; i < queue1.size(); i++)
    {
        s1 += queue1[i];
        q1.push(queue1[i]);
    }
    for (int i = 0; i < queue2.size(); i++)
    {
        s2 += queue2[i];
        q2.push(queue2[i]);
    }
    if ((s1 + s2) % 2 == 1)
        return -1;
    while (2 * (queue1.size() + queue2.size()) > answer)
    {
        if (s1 > s2)
        {
            now = q1.front();
            q1.pop();
            q2.push(now);
            s1 -= now;
            s2 += now;
        }
        else if (s2 > s1)
        {
            now = q2.front();
            q2.pop();
            q1.push(now);
            s2 -= now;
            s1 += now;
        }
        else
            return answer;
        answer++;

    }

    return -1;
}