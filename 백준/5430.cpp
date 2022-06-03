/*

문제 : 백준 AC
시간 : 60분
ide 활용 : o
질문 보기 : o
피드백 : 그냥 문자열 파싱해서 열심히 했다.
시간초과 뜨거나 틀렷다하는데 머가 틀린지 모르겠다...
새마음으로 다시 해야지
그냥 단순 구현으로 풀었다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	string arr;
	string s;
	string now;
	int find = 0;
	int mode = 1;

	int n;
	cin >> t;
	while (t--)
	{
		vector<int> temp;
		cin >> s;
		cin >> n;
		cin >> arr;
		for (int i = 0; i < arr.size(); i++)//문자열 파싱해서 temp에 넣기
		{
			if (arr[i] == ',' || arr[i] == ']' || arr[i] == '[')
			{
				if (now == "")
					continue;
				else
				{
					temp.push_back(stoi(now));
					now = "";
				}
			}
			else
			{
				now.push_back(arr[i]);
			}
		}

		for (int i = 0; i < s.size(); i++)//RD에 따라서 temp 고치기
		{
			if (s[i] == 'R')
			{
				if (mode == 1)
				{
					mode = 2;
				}
				else
				{
					mode = 1;
				}
			}
			else
			{
				if (temp.size() == 0)
				{
					find = 1;
					break;
				}
				else
				{
					if(mode == 1)
					{
						temp.erase(temp.begin());
					}
					else
					{
						temp.pop_back();
					}
				}
			}
		}
		if (find == 0)//결과값 출력하기
		{
			if (temp.size() == 0)
				cout << "[]";
			else
			{
				cout << "[";
				if (mode == 1)
				{
					for (int i = 0; i < temp.size() - 1; i++)
					{
						cout << temp[i] << ",";
					}
					cout << temp[temp.size()-1];
				}
				else
				{
					for (int i = temp.size() - 1; i > 0; i--)
					{
						cout << temp[i] << ",";
					}
					cout << temp[0];
				}
				cout << "]";
			}
			cout << "\n";
		}
		else
			cout << "error\n";
		find = 0;
		mode = 1;
	}

}