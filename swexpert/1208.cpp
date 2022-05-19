#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
	int N;
	int now;
	int answer = 0;
	vector<int> building;
	for (int test = 0; test < 10; test++)
	{
		scanf("%d", &N);
		for (int i = 0; i < 100; i++)
		{
			scanf("%d", &now);
			building.push_back(now);
		}

		for (int i = 0; i < N; i++)
		{
			int max	= max_element(building.begin(), building.end()) - building.begin();
			int min = min_element(building.begin(), building.end()) - building.begin();
			if (building[max] - building[min] == 0 || building[max] - building[min]==1)
			{
				break;
			}
			building[max]--;
			building[min]++;
		}
		answer = *max_element(building.begin(), building.end()) - *min_element(building.begin(), building.end());
		printf("#%d %d\n", test + 1, answer);
		answer = 0;
		building.clear();
	}

}