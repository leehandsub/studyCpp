/*
문제 : swea 최장 공통 부분 수열
시간 : 20분
ide 활용 : x
질문 보기 : x
피드백 : 조금 유명한? 알고리즘이다. 갯수는 dp로 풀 수 있기 때문에
dp를 사용했다. 직접 나타내는거를 볼려면 이분탐색을 이용해야한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

int dp[1002][1002];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		int len1, len2;
		string s1, s2;
		cin >> s1 >> s2;

		len1 = s1.size();
		len2 = s2.size();

		for (int i = 1; i <= len2; i++)
		{
			for (int j = 1; j <= len1; j++)
			{
				if (s2[i - 1] == s1[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;

				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		
		cout <<"#"<<t<<" " << dp[len2][len1]<<"\n";
	}
	
}