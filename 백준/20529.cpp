/*
문제 : 가장 가까운 세 사람의 심리적 거리 
시간 : 3시간
ide 활용 : o
질문 보기 : o
피드백 : 아직 잘모르겟다 왜 틀린지...
일단 set으로 10만개 넣는거부터 터진다.??? 그래서 set에서 잇는 것을 그냥 vector로 옮기는거도 시간초과 뜬따??????? 암만 많아도 16개인데
ㅇㅋ 근데 16C3인줄 알고 조합으로 했는데 터진다.!!!! 머지 내가 조합 잘못한건가 암튼 답을 보고 그냥 햇는데 된다....
나도 잘 이해가 아직 안된다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cstdio>

using namespace std;



int cmp_string(string a, string b)
{
	int sum = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			sum++;
	}
	return sum;
}

/*void Combination(vector<string> arr, vector<string> comb, int index, int depth)
{
	if (depth == comb.size())
	{
		for (int i = 0; i < comb.size(); i++)
		{
			ma = min(ma, cmp_string(comb[0], comb[1]) + cmp_string(comb[1], comb[2]) + cmp_string(comb[2], comb[0]));
		}

		return;
	}
	else
	{
		for (int i = index; i < arr.size(); i++)
		{
			comb[depth] = arr[i];
			Combination(arr, comb, i + 1, depth + 1);
		}
	}
}*/


int main(void)
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<string> arr;
		string temp;

		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			arr.push_back(temp);
		}

		
		if (n>32)
		{
			cout << "0" << "\n";
			continue;
		}

		int ma = 1999999999;
		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) { //최소 값 찾기를 한다.
					ma = min(ma, cmp_string(arr[i], arr[j]) + cmp_string(arr[j], arr[k]) + cmp_string(arr[i], arr[k]));
				}
			}
		}

		/*do {
			vector<string> ans;
			for (int i = 0; i < arr.size(); i++)
			{
				if(vit[i]==1)
				{
					ans.push_back(arr[i]);
				}
			}
			
			ma = min(ma, cmp_string(ans[0], ans[1]) + cmp_string(ans[1], ans[2]) + cmp_string(ans[2], ans[0]));

		} while (next_permutation(arr.begin(), arr.end()));*/

		cout << ma << "\n";
	}

}
