#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10][10];
int check[10][10];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int cnt = 0;
void dfs(int x,int y)
{
	int xx=0, yy=0;
	if (x==7&&y==7)
	{
		cnt++;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			xx = x + dx[i];
			yy = y + dy[i];
			if (check[xx][yy] == 0 && arr[xx][yy] == 0)
			{
				check[xx][yy] = 1;
				dfs(xx, yy);
				check[xx][yy] = 0;
			}
		}
	}
}

int main(void)
{
	int a, b;
//	scanf("%d %d", &N,&M);
	for (int i =0 ; i <10; i++)
	{
		for (int j = 0; j <10; j++)
		{
			arr[i][j] = 1;
		}
	}
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	check[1][1] = 1;
	dfs(1,1);
	printf("%d", cnt);

}
