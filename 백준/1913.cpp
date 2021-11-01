#include<stdio.h>
#include<iostream>

using namespace std;

int arr[1001][1001];

int main(void){
    
    int n;
    int x,y;
    int find;
    int i=1,j=1;
    int mode=1;//1남 2동 3북 4서
    int now;
    scanf("%d %d",&n,&find);
    now=n*n;
    while(now!=0)
    {
        if(arr[i][j]==0&&i<=n&&j<=n&&i!=0&&j!=0)
        {
            arr[i][j]=now;
            now--;
        }
        else
        {
            if(mode==1)
            {
                i--;
                mode=2;
            }
            else if(mode==2)
            {
                j--;
                mode=3;
            }
            else if(mode==3)
            {
                i++;
                mode=4;
            }
            else
            {
                j++;
                mode=1;
            }
        }
        
        if(mode==1)
            i++;
        if(mode==2)
            j++;
        if(mode==3)
            i--;
        if(mode==4)
            j--;
        
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
        {
            printf("%d ",arr[i][j]);
            if(arr[i][j]==find)
            {
                x=i;
                y=j;
            }
        }
        printf("\n");
    }
    printf("%d %d",x,y);
    
}
