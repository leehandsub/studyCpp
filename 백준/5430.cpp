/*

���� : ���� AC
�ð� : 60��
ide Ȱ�� : o
���� ���� : o
�ǵ�� : �׳� ���ڿ� �Ľ��ؼ� ������ �ߴ�.
�ð��ʰ� �߰ų� Ʋ�Ǵ��ϴµ� �Ӱ� Ʋ���� �𸣰ڴ�...
���������� �ٽ� �ؾ���
�׳� �ܼ� �������� Ǯ����.
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
		for (int i = 0; i < arr.size(); i++)//���ڿ� �Ľ��ؼ� temp�� �ֱ�
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

		for (int i = 0; i < s.size(); i++)//RD�� ���� temp ��ġ��
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
		if (find == 0)//����� ����ϱ�
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