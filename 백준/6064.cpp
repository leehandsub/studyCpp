/*
���� : ���� ī�� �޷�
�ð� : 25��
ide Ȱ�� : x
���� ���� : x
�ǵ�� : �ּҰ������ ���ؼ� �ִ븦 ��Ƴ���
�� ���ڸ� ���ϸ鼭 �������� print�ƴϸ� ���� ���� Ŀ���� �ؼ� Ǯ����.
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

int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int main(void)
{
	int t;
	int n, m;
	int x, y;
	
	scanf("%d", &t);
	while (t--)
	{
		int num = 0;
		int nx = 0, ny = 0;
		int i = 0;
		int j = 0;
		scanf("%d %d", &n, &m);
		scanf("%d %d", &x, &y);

		num = n * m / gcd(n, m);//�ּҰ����

		while (1)
		{
			nx = x + i * n;
			ny = y + j * m;
			if (nx > num || ny > num)
			{
				printf("-1\n");
				break;
			}
			if (nx == ny)
			{
				printf("%d\n", nx);
				break;
			}
			else if (nx > ny)
			{
				j++;
			}
			else
			{
				i++;
			}
		}
	}

}