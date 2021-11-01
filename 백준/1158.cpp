#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q;
int main(void)
{
	int x;
	int now = 0;
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}
    printf("<");
	while (1)
	{
		x = q.front();
		q.pop();
		now++;
		if(q.empty())
		{
		    printf("%d",x);
		    break;
		}
		if (now == M)
		{
			now = 0;
			printf("%d, ", x);
			continue;
		}
		q.push(x);
	}
    printf(">");

}
