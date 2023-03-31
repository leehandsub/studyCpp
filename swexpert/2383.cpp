/*
문제 : 점심 식사시간
시간 : 2시간 반?
ide 활용 : o
질문 보기 : x
피드백 : 단순 구현 문제이다.
먼저 계단과 사람의 좌표를 저장하고
조합으로 모든 사람과 2개의 계단에 대한 거리를 구하고 계단에 따라 사람을 나눈다.
그리고 while문을 돌면서 현재분에 대한 작업을 한다.
사람과 계단의 거리가 분보다 크면 in(계단에 들어간시간)++시켜준다. 그리고 3개 이상이면 멈추지만 혹시 계단을 다 건넛으면 추가를 하게 처리를 해준다.
complete로 계단을 다 건너사람을 처리했다.

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
#include <math.h>

using namespace std;

typedef struct person
{
	int x, y;
	int dis;
	int in;
	int complete;
	
	person(int X, int Y,int DIS,int IN,int COMPLETE)
	{
		x = X;
		y = Y;
		dis = DIS;
		in = IN;
		complete = COMPLETE;
	}
};

typedef struct stairs
{
	int x, y;
	int k;

	stairs(int X, int Y,int K)
	{
		x = X;
		y = Y;
		k = K;
	}
};

bool cmp(person p1, person p2)
{
	return p1.dis < p2.dis;
}

int main(void)
{
	int T;
	int n;
	int now;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d", &n);
		int ans = 1999999999;
		int arr[11][11] = { 0 };
		vector<person> persons;
		vector<stairs> st;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
					persons.push_back(person(j, i,0,0,0));
				else if (arr[i][j] != 0)
					st.push_back(stairs(j, i,arr[i][j]));
			}
		}
		/*
		- 계단을 내려가는 시간은 계단 입구에 도착한 후부터 계단을 완전히 내려갈 때까지의 시간이다.
        - 계단 입구에 도착하면, 1분 후 아래칸으로 내려 갈 수 있다.
        - 계단 위에는 동시에 최대 3명까지만 올라가 있을 수 있다.
        - 이미 계단을 3명이 내려가고 있는 경우, 그 중 한 명이 계단을 완전히 내려갈 때까지 계단 입구에서 대기해야 한다.
        - 계단마다 길이 K가 주어지며, 계단에 올라간 후 완전히 내려가는데 K 분이 걸린다.*/

		for (int i = 0; i <= persons.size(); i++)
		{
			vector<int> vit(persons.size());
			for (int j = 0; j < i; j++) 
			{
				vit[j] = 1;
			}
			do {
				vector<person> s1;
				vector<person> s2;
				int mini = 0;
				for (int j = 0; j < vit.size(); j++)
				{
					if (vit[j] == 0)
					{
						persons[j].dis = abs(st[0].x - persons[j].x) + abs(st[0].y - persons[j].y);
						s1.push_back(persons[j]);
					}
					else
					{
						persons[j].dis = abs(st[1].x - persons[j].x) + abs(st[1].y - persons[j].y);
						s2.push_back(persons[j]);
					}
				}

				sort(s1.begin(), s1.end(), cmp);
				sort(s2.begin(), s2.end(), cmp);
				while (1)
				{
					int com = 0;
					int cnt = 0;
					for (int j = 0; j < s1.size(); j++)
					{
						if (s1[j].complete == 1)
							com++;
						if (s1[j].dis < mini && s1[j].complete == 0)
						{
							s1[j].in++;
							if (s1[j].in > st[0].k)
							{
								s1[j].complete = 1;
								com++;
								cnt--;
								if (cnt < 0)
									cnt = 0;
							}
							else
							{
								cnt++;
							}
							if (cnt == 3)
								break;
						}//계단 도착

					}//1
					cnt = 0;
					for (int j = 0; j < s2.size(); j++)
					{
						if (s2[j].complete == 1)
							com++;
						if (s2[j].dis < mini && s2[j].complete == 0)
						{
							s2[j].in++;
							if (s2[j].in > st[1].k)
							{
								s2[j].complete = 1;
								com++;
								cnt--;
								if (cnt < 0)
									cnt = 0;
							}
							else
							{
								cnt++;
							}
							if (cnt == 3)
								break;
						}//계단 도착
					}//2
					if (com == persons.size())
						break;
					mini++;
				}
				ans = min(ans, mini);
			} while (prev_permutation( vit.begin(), vit.end()));
		}

		printf("#%d %d\n", test_case, ans);
	}
}
