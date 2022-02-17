#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer=-999;
int arr[250001];

int get_max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int solution(vector<vector<int>> triangle) {
    int k=4;
    int max=-1;
    arr[1]=triangle[0][0];
    if(triangle.size()==1)
        return triangle[0][0];
    arr[2]=arr[1]+triangle[1][0];
    arr[3]=arr[1]+triangle[1][1];
    if(triangle.size()==2)
        return get_max(arr[2],arr[3]);
    for(int i=2;i<triangle.size();i++)
    {
        for(int j=0;j<triangle[i].size();j++)
        {
            if(j==0)
                arr[k]=triangle[i][j]+arr[k-i];
            else if(j==triangle[i].size()-1)
                arr[k]=triangle[i][j]+arr[k-(i+1)];
            else
            {
                arr[k]=get_max(arr[k-i-1],arr[k-i])+triangle[i][j];
            }
            if(arr[k]>max)
                max=arr[k];
            k++;
        }
    }
    
    return max;
}
