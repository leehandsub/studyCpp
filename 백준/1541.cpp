#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	string now;
	string s;
	bool find = false;
	int answer = 0;
	cin>>s;

	for (int i = 0; i < s.size(); i++)
	{
		if (find == false)
		{
			if (s[i] == '-')
			{
				answer += stoi(now);
				now = "";
				find = true;
			}
			else if (s[i] == '+')
			{
				answer += stoi(now);
				now = "";
			}
			else
				now.push_back(s[i]);
		}
		else
		{
			if (s[i] == '+'|| s[i] == '-')
			{
				answer -= stoi(now);
				now = "";
			}
			else
				now.push_back(s[i]);
		}
	}
	if(find==false)
		answer += stoi(now);
	else
		answer -= stoi(now);

	printf("%d", answer);
}