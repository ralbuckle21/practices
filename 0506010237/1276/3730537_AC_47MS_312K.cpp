#include<iostream>
using namespace std;
int cash,n;
int num[20][2];
bool h[100010];
int main()
{
    while(scanf("%d %d",&cash,&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d %d",&num[i][0],&num[i][1]);
        memset(h,0,sizeof(h));  
        h[0]=true;
        for(int i=0;i<n;i++){
             int c=1;
             while(num[i][0]>0){
                 if(c>num[i][0]) c=num[i][0];
                 int v=c*num[i][1];
                 for(int w=cash;w>=v;w--)
                    if(h[w-v]) h[w]=true;
                 num[i][0]-=c;
                 c=c*2;
             }
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
