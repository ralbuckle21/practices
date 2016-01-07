#include<iostream>
using namespace std;
int t,n,num[13];//input
int ok=0;
void find(int k,int value,int sign[100],int len)
{
     int i;
     if(value==0)
     {
               for(i=0;i<len-1;i++)
                 printf("%d+",sign[i]); 
               printf("%d\n",sign[len-1]);
               ok=1;
              return;       
     }
     if(k==n)
       return;  
     if(value>=num[k])
     {
          sign[len]=num[k];
          find(k+1,value-num[k],sign,len+1);  
     }  
     for(i=k+1;i<n;i++)
     {
       if(value>=num[i] && num[i]!=num[i-1])
       {
          sign[len]=num[i];
          find(i+1,value-num[i],sign,len+1);  
       }
     }                 
}
int main()
{
    int i,sign[100];
    while(true)
    {
        scanf("%d %d",&t,&n);
        if(t==0 && n==0)
           break;
        for(i=0;i<n;i++)
          scanf("%d",&num[i]);
        printf("Sums of %d:\n",t);
        ok=0;
        find(0,t,sign,0);
        if(ok==0)
          printf("NONE\n");           
    }
    system("pause");
    return 0;   
}
