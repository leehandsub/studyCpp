/*
문제 : 암호코드 스캔
시간 : 5시간
ide 활용 : x
질문 보기 : x
피드백 : 정말 다사다난했다. 처음에는 암호를 받고 2진수를 고치면서 그에 따른 예외를 처리할려고 했는데
56배수보다 적거나 많거나 할 때, 맨뒤에 0일 때 조건 처리하기가 너무 힘들었다.
그래서 아예 처음부터 받을 때 새로운 배열을 만들어 모두 2진수로 표현하고 뒤에서 보며 1을 만낫을 때 암호를 확인하고
최대 공약수를 찾아 56*gcd만큼 새로운 문자열을 만들어 암호인지 아닌지 판단했다.시간이 다른사람보다 오래걸려 시간을 줄여봐야하나 생각이든다.
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

map<string, int> pass;

int gcd(int a, int b) {
	int tmp;
	while (b > 0) {
		tmp = a;
		a = b;
		b = (tmp % a);
	}
	return a;
}

string hexToBin[16] = {
	"0000"//0
	,"0001"//1
	,"0010"//2
	,"0011"//3
	,"0100"//4
	,"0101"//5
	,"0110"//6
	,"0111"//7
	,"1000"//8
	,"1001"//9
	,"1010"//A
	,"1011"//B
	,"1100"//C
	,"1101"//D
	,"1110"//E
	,"1111"//F
};

string convetHexToBin(char s)
{
	string temp;
	int idx = 0;
	
	if (s == 'A')
		idx = 10;
	else if (s == 'B')
		idx = 11;
	else if (s == 'C')
		idx = 12;
	else if (s == 'D')
		idx = 13;
	else if (s == 'E')
		idx = 14;
	else if (s == 'F')
		idx = 15;
	else
		idx = s - '0';
	temp = hexToBin[idx];
	
	return temp;
}

string changePassword(string s)
{
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		string temp;
		int gc = 0;
		int a = 0, b = 0, c = 0, d = 0;
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != '0')
			{
				i = j;
				break;
			}
			a++;
		}
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != '1')
			{
				i = j;
				break;
			}
			b++;
		}
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != '0')
			{
				i = j;
				break;
			}
			c++;
		}
		for (int j = i; j < s.size(); j++)
		{
			if (s[j] != '1')
			{
				i = j-1;
				break;
			}
			d++;
		}
		if ((a + b + c + d) %7 != 0)
			continue;
		gc = gcd(a, b);
		gc = gcd(gc, c);
		gc = gcd(gc, d);

		a /= gc;
		b /= gc;
		c /= gc;
		d /= gc;
		temp.push_back(a + '0');
		temp.push_back(b + '0');
		temp.push_back(c + '0');
		temp.push_back(d + '0');
		ans.push_back(pass[temp]+'0');
	}
	return ans;
}

int main(void)
{
	int T;
	int n,m;
	int now;

	pass.insert(make_pair("3211", 0));
	pass.insert(make_pair("2221", 1));
	pass.insert(make_pair("2122", 2));
	pass.insert(make_pair("1411", 3));
	pass.insert(make_pair("1132", 4));
	pass.insert(make_pair("1231", 5));
	pass.insert(make_pair("1114", 6));
	pass.insert(make_pair("1312", 7));
	pass.insert(make_pair("1213", 8));
	pass.insert(make_pair("3112", 9));

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		vector<string> arr;
		vector<string> hex;
		scanf("%d %d", &n,&m);
		string s;
		set<string> stringSet;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			arr.push_back(s);
		}
		s.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m;j++)
			{
				s = s + convetHexToBin(arr[i][j]);
			}
			hex.push_back(s);
			s.clear();
		}//16진수 string 넣기

		for (int i = 0; i < n; i++)
		{
			for (int j = hex[i].size()-1; j >= 0; j--)
			{
				int a=0, b=0, c=0;
				int gc = 0;
				int idx = 0;
				if (hex[i][j] == '1')
				{
					idx = j;
					for (int k = j; k >= 0; k--)
					{
						if (hex[i][k] == '0')
						{
							j = k;
							break;
						}
						c++;
					}
					for (int k = j; k >= 0; k--)
					{
						if (hex[i][k] == '1')
						{
							j = k;
							break;
						}
						b++;
					}
					for (int k = j; k >= 0; k--)
					{
						if (hex[i][k] == '0')
						{
							j = k;
							break;
						}
						a++;
					}
					gc = gcd(c, b);
					gc = gcd(gc, a);
					s = hex[i].substr(idx - 56 * gc + 1, 56 * gc);
					stringSet.insert(s);
					j = idx - 56 * gc;
					s.clear();
				}
			}
			
		}

		for (auto iter = stringSet.begin(); iter != stringSet.end(); iter++)
		{
			int password = 0;
			int pl = 0;
			s = changePassword(*iter);

			for (int i = 0; i < s.size(); i++)
			{
				if ((i + 1) % 2 == 1)
				{
					password +=( (s[i] - '0') * 3);
				}
				else
					password += (s[i] - '0') ;
				pl += (s[i] - '0');
			}
			if (password % 10 == 0)
				ans += pl;
		}

		printf("#%d %d\n", test_case, ans);
	}
}
