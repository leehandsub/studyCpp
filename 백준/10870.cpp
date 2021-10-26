#include <bits/stdc++.h>//앵간한 해더파일 다 추가

using namespace std;

int dp[25];

int main(){
    //ios::sync_with_stdio(false);//iostream에서 cin cout을 더 빠르게 해준다.iostream 함수인 cin/ cout을 stdio 함수인 getchar()
    //cin.tie(0);//무슨 버퍼 비우는 용도라는데 먼지는 모르겟다.
    int N;
    dp[0] = 0; 
    dp[1] = 1;
    for(int i=2;i<=20;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    scanf("%d",&N);
    printf("%d",dp[N]);
}
