#include <stdio.h>
#include <iostream>
using namespace std;

int reverse(int x)
{
	int num=0;
	for (int i = 0; i < 6; i++)
	{
		num *= 10;
		num += x % 10;
		x /= 10;
		if (x == 0)
		{
			break;
		}
	}
	return num;
}
bool isPrime(int x)
{
	int cnt = 0;
	if (x == 1) return false;
	//if (x == 2) return true;
	for (int i = 2; i < x; i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;

}

int main(void)
{
	int cnt[10] = { 0 };
	int N;
	int num=0;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d", &num);
		num = reverse(num);
		if (isPrime(num))printf("%d ", num);
	}
}
