#include<iostream>
using namespace std;
int cash,n;
int num[20][2];
bool h[100010];
int main()
{
    while(scanf("%d%d",&cash,&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d %d",&num[i][0],&num[i][1]);
        memset(h,0x00,sizeof(h));  
        h[0]=true;
        int sum=0;
        for(int i=0;i<n;i++)
             for(int j=1;j<=num[i][0];j++){
                   sum+=num[i][1];  
                   if(sum>cash) sum=cash;
                   for(int w=num[i][1];w<=sum;w++)
                        if(h[w-num[i][1]]) 
                             h[w]=true;
             }
        for(int i=cash;i>=0;i--) 
             if(h[i]){
                  printf("%d\n",i);
                  break;         
             }          
    }
    system("pause");
    return 0;
}
