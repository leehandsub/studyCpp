#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int max = 0;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (k == j)
                    continue;
                if (max < land[i - 1][k])
                {
                    max = land[i - 1][k];
                }
            }
            land[i][j] += max;
            max = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (answer < land[land.size() - 1][i])
            answer = land[land.size() - 1][i];
    }

    return answer;
}