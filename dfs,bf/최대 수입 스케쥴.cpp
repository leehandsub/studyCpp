#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Data {
	int money;
	int when;
	Data(int a, int b) {
		money = a;
		when = b;
	}
	bool operator<(const Data& b)const {
		return when > b.when;
	}//자동으로 내림차순 b.when뒤에꺼 
};
int main(void)
{
	int now = 0;
	int N, M;
	int x, y;
	int max = -999999;
	priority_queue<int> q;
	vector<Data> a;
	scanf("%d", &N);
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &x, &y);
		a.push_back(Data(x, y));
		if (y > max)
		{
			max = y;
		}
	}
	sort(a.begin(), a.end());
	for (int i = max; i >= 1; i--)
	{
		for (int j = now; j < N; j++)
		{
			if (a[j].when < i)
			{
				now = j;
				break;
			}
			if(a[j].when==i)
				q.push(a[j].money);
		}
		if (!q.empty())
		{
			res += q.top();
			q.pop();
		}
	}
	printf("%d", res);

}
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Data{
	int x,y,z;
	Data(int a, int b, int c)
	{
		x=a;
		y=b;
		z=c;
	}
	bool operator<(const Data &b)const{//구조체 주소로 왓다. b를 바꾸면 안되기 위해 const
		return x<b.x;//	b.x가 뒤다.오름차순
		if(x!=b.x)return x<b.x;
		if(y!=b.y)return y<b.y;
		if(z!=b.z)return z<b.z;//x,y가 같은때
	}	//정렬기준 오버로딩 c++ 클래스참고 상수 멤버함수...xyz를 바꾸려고 하면 오류
	
};

int main(void)
{
	vector<Data> a;
	x.push_back(Data(2,3,5));	
	sort(a.begin(),a.end());

}//구조체 vector 사용법, 정렬 기준 정하기
*/
