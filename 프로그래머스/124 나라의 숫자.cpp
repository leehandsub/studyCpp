/*
���� : ���α׷��ӽ� lv 2 124 ������ ����
�ð� : 20��
ide Ȱ�� : x
���� ���� : x
�ǵ�� : ��� �ڹ� �ѹ������Ѵٰ� Ǯ���� ������.
n--�� ���̾�!
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