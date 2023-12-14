/*
문제 : 두 개의 배열
시간 : 15분
ide 활용 : o
질문 보기 : o
피드백 : 이분탐색으로 풀엇다. 그냥 구현하라고 하면 몰루??
lower_bound, upper_bound도 조금 공부해야겟다.
long long 까먹고 double로 해서 계속 틀렷다.
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
	int t;
	int n;
	int m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		long long sum = 0;
	
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		sort(b.begin(), b.end());
		for (int i = 0; i < n; i++)
		{
			int ind = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			if (ind >= m)
			{
				ind = m - 1;
			}
			
			if (ind != 0)
			{
				int num = abs(a[i] - b[ind - 1])- abs(a[i] - b[ind]);
				if (num <= 0)//ind의 차이가 더크다.
				{
					ind = ind - 1;
				}
			}
//			cout << ind << " ";
			sum +=(long long) b[ind];
		}
		cout << sum << "\n";
	}

	
}
