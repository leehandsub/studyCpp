/*
문제 : 곰곰이와 시소
시간 : 1시간
ide 활용 : o
질문 보기 : o
피드백 : 이분 탐색까지는 좋았는데 left,right를 어떻게 해야할지 잘몰랏는데
그냥 하면됐다. 왜??? 암튼 cout은 반올림 안하는데 printf(lf)는 반올림 해줘서 계속 틀렸다.

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
	int n;
	int l;
	cin >> n >> l;
	vector<double> pos(n);
	vector<double> weight(n);

	for (int i = 0; i < n; i++)
	{
		cin >> pos[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	double left = 0;
	double right = l;
	double mid = 0;

	while (right - left > 0.00000001)
	{
		mid = (left + right) / 2.0;
		double l_sum = 0;
		double r_sum = 0;

		for (int i = 0; i < n; i++)
		{
			if(mid<=pos[i])
				r_sum += ((pos[i] - mid) * weight[i]);
			else
				l_sum += ((mid - pos[i]) * weight[i]);
		}
	
		if (r_sum > l_sum)
		{
			left = mid;
		}
		else 
		{
			right = mid;
		}
		
	}
	printf("%lf", left);

}
