/*
문제 : pr lv1 성격 유형 검사하기

시간 : 10분
ide 활용 : x
질문 보기 : x
피드백 : 어떻게 덜 귀찮게 짤까 고민했다. 하지만 방법이 잘 안떠올라 무식하게 짯다.
다른사람 것을 보니 미리 RT같은것을 넣어둘걸 그랬다.
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

int al[30];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    string temp;
    for (int i = 0; i < survey.size(); i++)
    {
        if (choices[i] < 4)
        {
            al[survey[i][0] - 'A'] += 4 - choices[i];
        }
        else
        {
            al[survey[i][0] - 'A'] += choices[i] - 4;
        }
    }
    if (al['R' - 'A'] < al['T' - 'A'])
        temp = "R";
    else
        temp = "T";
    if (al['C' - 'A'] < al['F' - 'A'])
        temp.push_back('F');
    else
        temp.push_back('C');
    if (al['J' - 'A'] < al['M' - 'A'])
        temp.push_back('M');
    else
        temp.push_back('J');
    if (al['A' - 'A'] < al['N' - 'A'])
        temp.push_back('N');
    else
        temp.push_back('A');

    return temp;
}


int main(void)
{

    string TEMP = solution({ "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 });

    if ("TCMA" == TEMP)
        printf("1");
    else
        printf("0");
}