#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int qe[100];
int front=-1, rear=-1;
int check[10];
vector <int> a[10];
int main(void)
{
	int b, c;
	int x;
	for (int i = 0; i < 6; i++)
	{
		scanf("%d %d", &b, &c);
		a[b].push_back(c);
		a[c].push_back(b);
	}
	qe[++rear] = 1;
	check[0] = 1;
	while (front < rear)
	{
		x = qe[++front];
		printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++)
		{
			if (check[a[x][i]-1] == 0)
			{
				check[a[x][i]-1] = 1;
				qe[++rear] = a[x][i];
			}
		}
	}
}
