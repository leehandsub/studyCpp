/*
문제 :입국심사
시간 :60분
ide 활용 : x
질문 보기 : o
피드백 : 처음에 문제를 봐도 완탐은 절대 아닌데 어떻게 풀지 생각하다 답을 봣다.
시간을 중심으로 가능한 시간을 이분탐색으로 구하는 문제다.
범위 생각을 못해서 unsigned 문제를 찾는다고 오래 걸렷다....
이분탐색 할 때마다 감으로 하는거 같은데 한번 제대로 봐야겟다.
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

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	int num;

	cin >> n >> m;
	vector<unsigned long long> arr;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr.push_back(num);
	}
	unsigned long long left = 0;
	unsigned long long right = m * (*max_element(arr.begin(), arr.end()));
	unsigned long long mid = 0;
	while (left<=right)
	{
		mid = (left + right) / 2;
		unsigned long long temp = 0;
		for (int i = 0; i < n; i++)
		{
			temp +=  mid/ arr[i];
		}

		if (temp >= m)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << left;

}
