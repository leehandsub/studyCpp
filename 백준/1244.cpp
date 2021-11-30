#include <stdio.h>
#include <vector>

using namespace std;

int arr[101];

int main(void)
{
    int n,m;
    int s,now;
    int j=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&s,&now);
        
        if(s==1)//남
        {
            while(now*j<=n)
            {
                if(arr[now*j]==0)
                    arr[now*j]=1;
                else
                    arr[now*j]=0;
                j++;
            }

        }
        else//여
        {
            if(arr[now]==0)
                arr[now]=1;
            else
                arr[now]=0;
            while(1)
            {
                if(now-j<=0||now+j>n)
                    break;
                if(arr[now-j]==arr[now+j])
                {
                    if(arr[now-j]==0)
                        arr[now-j]=1;
                    else
                        arr[now-j]=0;
                    if(arr[now+j]==0)
                        arr[now+j]=1;
                    else
                        arr[now+j]=0;
                    j++;
                }
                else
                    break;
            }
        }
        j=1;

    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
        if(i%20==0)
            printf("\n");
    }
    
}
