/*
���� : ���� IOIOI
�ð� : 40��
ide Ȱ�� : o
���� ���� : x
�ǵ�� : �ش��ϴ� ��츦 ���� ã�� n�� �´� ������ ã���ִ� ���� �ݺ��ߴ�.
		i = find+(n-1)*2; �̺κ��� ���� �߿��ϴ�.
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
	int n, m;
	string in;
	string now;
	int find = 0;
	int cnt = 0;
	string temp = "IOI";
	scanf("%d", &n);
	scanf("%d", &m);
	cin >> in;

	for (int i = 1; i < n; i++)
	{
		temp += "OI";
	}
	int i =0;
	while (1)
	{
		find = in.find(temp,i);
		if (find == string::npos&&i==0)
		{
			printf("0");
			return 0;
		}
		else if (find == string::npos)
		{
			break;
		}
		i = find+(n-1)*2;
		while (i+2<in.size())
		{
			if (in[i + 1] != 'O' || in[i + 2] != 'I')
				break;
			i += 2;
			cnt++;
		}
	}
	printf("%d", cnt);

}