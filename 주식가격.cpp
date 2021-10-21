#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> st;
    int arr[1000001];
    for(int i=0;i<prices.size();i++)
    {
        answer.push_back(prices.size()-1-i);
        arr[i]=prices.size()-1-i;
    }
    
    for(int i=0;i<prices.size();i++)
    {

        while(!st.empty()&&st.top().first>prices[i])
        {
            answer[st.top().second]=arr[st.top().second]-arr[i];
            st.pop();
        }
        st.push(make_pair(prices[i],i));
    }

    return answer;
}
