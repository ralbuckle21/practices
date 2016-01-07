#include<iostream>
using namespace std;
int t,n,num[13];//input
int result[50];
void find(int k,int value,int sign[100],int len)
{
     int i;
     if(value==0)
     {
           int ok=0;
           for(i=0;i<len;i++)
                if(result[i]!=sign[i])
                {
                      ok=1;
                      break;                  
                }
           if(ok==1)
           {
               for(i=0;i<len-1;i++)
                 printf("%d+",sign[i]); 
               printf("%d\n",sign[len-1]);
               for(i=0;i<len;i++)
                 result[i]=sign[i];
              return;
           }         
     }
     if(k==n)
       return;    
     for(i=k;i<n;i++)
       if(value>=num[i])
       {
          sign[len]=num[i];
          find(i+1,value-num[i],sign,len+1);  
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
        for(i=0;i<30;i++)
           result[i]=0;
        find(0,t,sign,0);
        if(result[0]==0)
          printf("NONE\n");           
    }
    system("pause");
    return 0;   
}
