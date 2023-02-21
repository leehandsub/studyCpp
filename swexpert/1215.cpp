/*
문제 : 회문1
시간 : 20분?
ide 활용 : x
질문 보기 : x
피드백 : 그냥 완탐으로 풀었다.
for문을 돌면서 각 원소마다 오른쪽 아래쪽을 확인해서 회문인지를 확인했다.

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
int n;
 
int circular(vector<string> arr,int startI,int startJ) {
 
    string temp;
    int cnt = 0;
    int flag = 1;
 
    if (startI + n - 1 < 8)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[startI + i][startJ] != arr[n + startI - i - 1][startJ])
            {
                flag = 0;
                break;
            }
            else
                flag = 1;
        }
        if (flag == 1)
            cnt++;
    }
    if (startJ + n - 1 < 8)
    {
        flag = 1;
        for (int i = 0; i < n / 2; i++)
        {
            if (arr[startI][startJ + i] != arr[startI][startJ + n - i - 1])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            cnt++;
    }
     
 
    return cnt;
 
}
 
 
int main(void)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    for (test_case = 1; test_case <= 10; ++test_case)
    {
 
        vector<string> arr;
        string s;
        cin >> n;
        int ans = 0;
 
        for (int i = 0; i < 8; i++)
        {
            cin >> s;
            arr.push_back(s);
        }
 
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                ans += circular(arr, i, j);
            }
        }
         
        printf("#%d %d\n", test_case, ans);
    }
 
}
