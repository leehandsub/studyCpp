#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int money[10001];

int park(string s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    string now = "";
    string time = "";
    string find = "";
    vector<pair<string, string>> arr(10001);
    int cal = 0;

    for (int i = 0; i < records.size(); i++)
    {
        now = records[i].substr(6, 4);
        time = records[i].substr(0, 5);
        for (int j = 11; j < records[i].size(); j++)
        {
            find.push_back(records[i][j]);
        }

        if (find == "IN")
        {
            arr[stoi(now)] = make_pair(time, find);
        }
        else if(find=="OUT")
        {
            cal = park(time) - park(arr[stoi(now)].first);
            money[stoi(now)] += cal;
            arr[stoi(now)].second = find;
        }
        find = "";
    }

    for (int i = 0; i < arr.size(); i++)
    {
        
        if (arr[i].second != "")
        {
            if (arr[i].second == "IN")
            {
                cal = park("23:59") - park(arr[i].first);
                money[i] += cal;
            }
            cal = fees[1];
            if (money[i] > fees[0])
            {
                cal += ((money[i] - fees[0]) / fees[2] * fees[3]);
                if ((money[i] - fees[0]) % fees[2] != 0)
                    cal += fees[3];
            }
            answer.push_back(cal);
        }
    }

    return answer;
}
