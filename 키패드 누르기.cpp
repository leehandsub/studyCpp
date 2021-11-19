#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int rx=1,ry=4;
    int lx=3,ly=4;
    
    for(int i=0;i<numbers.size();i++)
    {
        if(numbers[i]==0)
            numbers[i]=11;
        if(numbers[i]==1||numbers[i]==4||numbers[i]==7)
        {
            lx=1;
            ly=numbers[i]/3+1;
            answer+="L";
        }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9)
        {
            rx=3;
            ry=numbers[i]/3;
            answer+="R";
        }
        else
        {
            if(abs((numbers[i]/3+1)-ry)+abs(2-rx)>
               abs((numbers[i]/3+1)-ly)+abs(2-lx))
            {
                lx=2;
                ly=numbers[i]/3+1;
                answer+="L";
            }
            else if(abs((numbers[i]/3+1)-ry)+abs(2-rx)<
               abs((numbers[i]/3+1)-ly)+abs(2-lx))
            {
                rx=2;
                ry=numbers[i]/3+1;
                answer+="R";
            }
            else
            {
                if(hand=="right")
                {
                    rx=2;
                    ry=numbers[i]/3+1;
                    answer+="R";
                }
                else
                {
                    lx=2;
                    ly=numbers[i]/3+1;
                    answer+="L";
                }
            }
        }
    }
    return answer;
}
