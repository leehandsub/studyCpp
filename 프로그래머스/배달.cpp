#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <pair<int, int>> temp[51];

int solution(int N, vector<vector<int> > road, int K) {

    int answer = 0;
    priority_queue<pair<int, int>> pq;
    vector <int> dist;
    int x, y, z;
    for (int i = 0; i <= N; i++)
    {
        dist.push_back(999999999);
    }

    for (int i = 0; i < road.size(); i++)
    {
        x = road[i][0];
        y = road[i][1];
        z = road[i][2];

        temp[x].push_back(make_pair(y, z));
        temp[y].push_back(make_pair(x, z));
    }

    pq.push(make_pair(0, 1));
    dist[1] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < temp[cur].size(); i++)
        {
            x = temp[cur][i].first;
            y = temp[cur][i].second;
            if (dist[x] > cost + y)
            {
                dist[x] = cost + y;
                pq.push(make_pair(-dist[x], x));
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }

    return answer;
}