#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include<vector>
using namespace std;

int main(void) {

	string s1, s2;
	string result;
	cin >> s1;
	cin >> s2;


	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] - '0' >= 0 && s1[i] - '0' <= 9)
		{
			continue;
		}
		result.push_back(s1[i]);
	}
	if (result.find(s2) == -1)
	{
		printf("0");
	}
	else
	{
		printf("1");
	}

}
