/*
문제 :무선 충전
시간 : 3시간?
ide 활용 : o
질문 보기 : o
피드백 : 먼저 3차원 배열로 map을 그리고 a,b가 움직이면서 확인을 했다.
그래서 a위치일 때 0,1, 2이상일 때 경우의 수를 모두 나눠서 b위치에서 0,1,2이상 경우의 수를 나눴다.
그래서 9가지 경우의 수에 대응함.
제일 어려운 a,b둘다 2 이상일때 처리가 제일 힘들었다. 어떻게 해야할지 여러 방법을 했는데
결국 모든 조합에서 2개를 뽑아 제일 큰값을 뽑게 했다. 
질문은 다른사람들이 틀리는 경우의 수를 봣는데 애초에 초기 input부터 계속 틀리고 초기 input이 맞으니 그냥 통과 됐다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

int n;

int dx[5] = { 0,0,1,0,-1 };
int dy[5] = { 0,-1,0,1,0 };

int main(void)
{
	int T;
	int m, a;
	int bx, by;
	int w;

	freopen("input.txt", "r", stdin);//a 1,1 b 10,10
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		vector<vector<vector<int>>> arr;//map 3차원 벡터
		for (int i = 0; i < 11; i++)
		{
			vector<vector<int>> t;
			for (int j = 0; j < 11; j++)
			{
				vector<int> t2;
				t.push_back(t2);
			}
			arr.push_back(t);
		}

		int ma[101] = { 0 };//a 길
		int mb[101] = { 0 };//b 길
		int p[9] = { 0 };
		scanf("%d %d", &m, &a);

		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &ma[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &mb[i]);
		}
		for (int i = 1; i <= a; i++)//맵 만들기
		{
			scanf("%d %d", &bx, &by);
			scanf("%d %d", &w,&p[i]);//w 범위, p 세기
			for (int j = -w; j <= w; j++)
			{
				for (int k = -w; k <= w; k++)
				{
					int nx = bx + j;
					int ny = by + k;
					if (nx > 10 || nx <= 0 || ny > 10 || ny <= 0)
						continue;
					if ((abs(j)+abs(k)) > w)
						continue;
					arr[by+k][bx+j].push_back(i);
				}
			}
		}

		int moveAX = 1;
		int moveAY = 1;
		int moveBX = 10;
		int moveBY = 10;
		int sum = 0;

		for (int i = 0; i <= m; i++)
		{
			moveAX += dx[ma[i]];
			moveAY += dy[ma[i]];
			moveBX += dx[mb[i]];
			moveBY += dy[mb[i]];

			if (arr[moveAY][moveAX].size() == 0)//0
			{
				sum += 0;
				if (arr[moveBY][moveBX].size() != 0)
				{
					int ma = 0;
					for (int j = 0; j < arr[moveBY][moveBX].size(); j++)
					{
						if (ma < p[arr[moveBY][moveBX][j]])
						{
							ma = p[arr[moveBY][moveBX][j]];
						}
					}
					sum += ma;
				}
			}
			else if (arr[moveAY][moveAX].size() == 1)//1
			{
				if (arr[moveBY][moveBX].size() == 0)
				{
					sum += p[arr[moveAY][moveAX][0]];
				}
				else if (arr[moveBY][moveBX].size() == 1)
				{
					sum += p[arr[moveAY][moveAX][0]];
					if (arr[moveBY][moveBX][0] != arr[moveAY][moveAX][0])
						sum += p[arr[moveBY][moveBX][0]];
				}
				else
				{
					sum += p[arr[moveAY][moveAX][0]];
					int ma = 0;
					for (int j = 0; j < arr[moveBY][moveBX].size(); j++)
					{
						if (arr[moveAY][moveAX][0] == arr[moveBY][moveBX][j])
							continue;
						if (ma < p[arr[moveBY][moveBX][j]])
							ma = p[arr[moveBY][moveBX][j]];
					}
					sum += ma;
				}
			}
			else
			{
				if (arr[moveBY][moveBX].size() == 0)
				{
					int ma = 0;
					for (int j = 0; j < arr[moveAY][moveAX].size(); j++)
					{
						if (ma < p[arr[moveAY][moveAX][j]])
						{
							ma = p[arr[moveAY][moveAX][j]];
						}
					}
					sum += ma;
				}
				else if (arr[moveBY][moveBX].size() == 1)
				{
					int ma = 0;
					int idx = 0;
					for (int j = 0; j < arr[moveBY][moveBX].size(); j++)
					{
						if (ma < p[arr[moveBY][moveBX][j]])
						{
							idx = arr[moveBY][moveBX][j];
							ma = p[arr[moveBY][moveBX][j]];
						}
					}
					sum += ma;
					ma = 0;
					for (int j = 0; j < arr[moveAY][moveAX].size(); j++)
					{
						if (arr[moveAY][moveAX][j] == idx)
							continue;
						if (ma < p[arr[moveAY][moveAX][j]])
						{
							ma = p[arr[moveAY][moveAX][j]];
						}
					}
					sum += ma;
				}
				else
				{
					vector<pair<int, int>> com;
					vector<int> vit;

					for (int j = 0; j < arr[moveAY][moveAX].size(); j++)
					{
						com.push_back(make_pair(arr[moveAY][moveAX][j], 1));
						vit.push_back(0);
					}
					for (int j = 0; j < arr[moveBY][moveBX].size(); j++)
					{
						com.push_back(make_pair(arr[moveBY][moveBX][j], 2));
						vit.push_back(0);
					}
					
					vit[0] = 1;
					vit[1] = 1;
					
					int ma = 0;
					do {
						vector<pair<int, int>> temp;
						for (int j = 0; j < vit.size(); j++)
						{
							if (vit[j] == 1)
								temp.push_back(com[j]);
						}
						if (temp[0].second == temp[1].second)
						{
							continue;
						}
						if (temp[0].first == temp[1].first)
							continue;

						ma = max(ma, p[temp[1].first] + p[temp[0].first]);

					} while (prev_permutation(vit.begin(), vit.end()));
					sum += ma;
				}
			}
		}

		printf("#%d %d\n", test_case, sum);
	}
}
