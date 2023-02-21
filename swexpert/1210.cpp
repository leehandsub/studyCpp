/*
문제 : Ladder1
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 계속 올라가면서 왼쪽 오른쪽 있는 확인한 다음 방문을 체크 해놓고
가로로 갓을 때는 위로 가게 한다.
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
 
 
int main(void)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    for (test_case = 1; test_case <= 10; ++test_case)
    {
        cin >> T;
        int arr[101][101] = { 0 };
        int vit[101][101] = { 0 };
        int startI=0;
        int startJ=0;
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                scanf("%d", &arr[i][j]);
                if (arr[i][j] == 2)
                {
                    startI = i;
                    startJ = j;
                }
            }
        }
        int i = startI;
        int j = startJ;
        int flag = 0;
        while (i!=0)
        {
            vit[i][j] = 1;
            if (flag == 0)
            {
                if (arr[i][j - 1] == 1&&vit[i][j - 1]==0)//왼쪽
                    flag = 1;
                else if (arr[i][j + 1] == 1 && vit[i][j + 1] == 0)//오른쪽
                    flag = 2;
                else
                    i--;
            }
            else
            {
                if (flag == 1)
                    j--;
                else
                    j++;
                if (arr[i - 1][j] == 1)
                {
                    flag = 0;
                }
            }
        }
        printf("#%d %d\n", test_case, j);
    }
 
}
