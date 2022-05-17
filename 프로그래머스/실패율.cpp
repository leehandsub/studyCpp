#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double arr[502];

bool compare(const pair<double, int>& a, const pair<double, int>& b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> temp;
    double now = stages.size();
    for (int i = 0; i < stages.size(); i++)
    {
        arr[stages[i]]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (now == 0)
            temp.push_back(make_pair(0, i));
        else
            temp.push_back(make_pair(arr[i] / now, i));
        now -= arr[i];
    }
    sort(temp.begin(), temp.end(), compare);
    for (int i = 0; i < temp.size(); i++)
    {
        answer.push_back(temp[i].second);
    }
    return answer;
}