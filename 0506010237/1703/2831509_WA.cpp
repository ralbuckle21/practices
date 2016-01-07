#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define M   100001
struct Crime
{
   int parent,weight;
};
Crime crime[M];
int n,m;
main( )
{
   int k,one,two;
   char order;
   int kk,X;
   scanf("%d",&X);
   for(kk=0;kk<X;kk++){
      memset(crime,0,sizeof(crime));		
      scanf("%d%d",&n,&m);
      for(k=0;k<m;k++)
      {
         order=getchar();			
         scanf("%d%d",&one,&two);
         if(order=='D')
         {   
            int temp1=one,temp2=two,t1=0,t2=0;
            while(crime[temp1].parent!=0) 
            {
               t1+=crime[temp1].weight;
               temp1=crime[temp1].parent;
            }
            while(crime[temp2].parent!=0)
            {
               t2+=crime[temp2].weight;
               temp2=crime[temp2].parent;
            }    
            if(temp1!=temp2)
            {
               if(t1<t2)
               {  
                  crime[temp1].parent=temp2;
                  crime[temp1].weight=(t1-t2+1)%2;
               }
               else 
               {       
                  crime[temp2].parent=temp1;
                  crime[temp2].weight=(t1-t2+1)%2;
               }
            }
         }
         else
         {    
            int temp1=one,temp2=two,t1=0,t2=0;
            while(crime[temp1].parent!=0)
            {
               t1+=crime[temp1].weight;
               temp1=crime[temp1].parent;
            }
            while(crime[temp2].parent!=0) 
            {
               t2+=crime[temp2].weight;
               temp2=crime[temp2].parent;
            }	
            if(temp1!=temp2)		// 不在同一棵树
               printf("Not sure yet.\n");
            else if((t2-t1)%2==0)     // 权相差为偶数
               printf("In the same gang.\n");
            else                      // 权相差为一个奇数
               printf("In different gangs.\n");
         }
      }
   }
   return 1;
}

