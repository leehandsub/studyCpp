/*
문제 : 프로그래머스 lv 2 124 나라의 숫자
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 사실 자바 한번연습한다고 풀었던 문제다.
n--는 신이야!
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

string solution(int n) {
    string answer = "";
    string now;
    while (n)
    {
        if (n % 3 == 0)
        {
            now = "4";
            n--;
        }
        else
            now = to_string(n % 3);

        answer = now + answer;
        n = n / 3;
    }
    return answer;
}