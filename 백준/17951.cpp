/*
문제 : 흩날리는 시험지 속에서 내 평점이 느껴진거야
시간 : 2시간
ide 활용 : o
질문 보기 : o
피드백 : 어떻게 풀어야하는지 몰라 힌트를 보고 풀엇다.
이분탐색으로 풀엇다. 최소값을 이분탐색으로 찾는다.
왜 이렇게 하는지는 알겟는데 이해가 안되는 부분이 cnt찾는 부분이다. 최솟값을 구해야하긴 하는데 왜 이렇게 구현해야지??
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
#include <cstdio>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);

	int right = n;
	int left = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		right+=arr[i];
	}


	while (left+1<right)
	{
		int mid = (right + left) / 2;
		int ans = 0;
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
			if (sum > mid)
			{
				sum = 0;
				ans++;
			}
		}

		if (ans >= k)
		{
			left = mid;
		}
		else if (ans < k)
		{
			right = mid;
		}
	}

	cout << right;
}
