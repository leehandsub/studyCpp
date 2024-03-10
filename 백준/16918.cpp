/*
문제 :봄버맨
시간 :40분
ide 활용 : o
질문 보기 : X
피드백 : 단순 구현이다.
%c로 받으니까 \n 받는 것을 찾는게 오래걸렷다. 
한번에 펑 터트려야하기 것을 구현하는 걸 조금 이상하게 구현하거 같다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <stack>
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;

char arr[205][205];

int r, c, n;

void install_x()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] != 'O')
            {
                arr[i][j] = 'X';
            }
        }
    }
}
void install_o()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] != 'X')
            {
                arr[i][j] = 'O';
            }
        }
    }
}
void boom_o()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 'O')
            {
                arr[i][j] = '.';
                if (arr[i][j + 1] != 'O')
                {
                    arr[i][j + 1] = '.';
                }
                if (arr[i][j - 1] != 'O')
                {
                    arr[i][j - 1] = '.';
                }
                if (arr[i + 1][j] != 'O')
                {
                    arr[i + 1][j] = '.';
                }
                if (arr[i - 1][j] != 'O')
                {
                    arr[i - 1][j] = '.';
                }
            }
            
        }
    }
}
void boom_x()
{
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 'X')
            {
                arr[i][j] = '.';
                if (arr[i][j + 1] != 'X')
                {
                    arr[i][j + 1] = '.';
                }
                if (arr[i][j - 1] != 'X')
                {
                    arr[i][j - 1] = '.';
                }
                if (arr[i + 1][j] != 'X')
                {
                    arr[i + 1][j] = '.';
                }
                if (arr[i - 1][j] != 'X')
                {
                    arr[i - 1][j] = '.';
                }
            }
           
        }
    }
}


int main(void)
{
   /* cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);*/


    cin >> r >> c >> n;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            scanf(" %c", &arr[i][j]);
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (i % 4 == 2)
        {
            install_x();
        }
        if (i % 4 == 3)
        {
            boom_o();
        }
        if (i % 4 == 0)
        {
            install_o();
        }
        if (i % 4 == 1)
        {
            boom_x();
        }
    }

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (arr[i][j] == 'X')
            {
                arr[i][j] = 'O';
            }
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

}//인선 예슬
    
