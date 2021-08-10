#include <stdio.h>
#include <iostream>
using namespace std;

int main(void)
{
	int cnt = 0;
	int res = 0;
	int N;
	int num=2;

	scanf("%d", &N);
	for(int i=2;i<=N;i++)
	{
		res = 1;
		for (int j = 2; j*j <= i; j++)
		{
			if (i % j == 0)
			{
				res = 0;
				break;
			}
		}
		if (res == 1)cnt++;
		
	}
	printf("%d", cnt);
}//ex)n==36 1x36 2x18 3x12 4x9 6x6인데 36 18 12 9 볼 필요도 없이 약수가 무조건 있기 때문에 확인할 필요가 없다.
//그래서 36제곱근까지만 확인 하면 된다.
