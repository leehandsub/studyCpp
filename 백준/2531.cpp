/*
문제 : 회전 초밥
시간 : 30분
ide 활용 : x
질문 보기 : x
피드백 : 단순 구현인데 실수를 너무 많이 했다.(인덱스 계산같은거)...
한바퀴 쭉 돌면서set에 저장하여 갯수를 계쏙 찾앗다.
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;

    int N, d, k, c; 
    int answer = 0;
    vector<int> arr;

    cin >> N >> d >> k >> c;

    vector<int> cho(d+1, 0);
       
    for (int i = 0;i < N;i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    set<int> s;
    for (int i = 0;i < k;i++)
    {
        s.insert(arr[i]);
        cho[arr[i]]++;
    }
    if (s.find(c) == s.end())
    {
        s.insert(c);
    }
    answer = s.size();

    for(int i=k;i<N;i++)
    {
        cho[arr[i - k]]--;
        if(cho[arr[i-k]] <= 0)
            s.erase(arr[i - k]);

        s.insert(arr[i]);
        cho[arr[i]]++;

        s.insert(c);
        int size = s.size();
        answer = max(answer, size);
    }
    int i = 0;
    for (i = 0;i < k;i++)
    {
        cho[arr[i + N - k]]--;
        if (cho[arr[i + N - k]] <= 0)
            s.erase(arr[i+ N-k]);

        s.insert(arr[i]);
        cho[arr[i]]++;

        s.insert(c);
        int size = s.size();
        answer = max(answer, size);
    }
    cout << answer;

}

