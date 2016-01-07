#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
     int value;
     int count;       
}node;
int n,front=0,rear=0,ce=0;
long long int sum=0,summax=0;
node re[200],result[200];
void findup(int *min,int sum,int i,int j)
{
       int  k=i,m=j;
       while(k>0 && m<=n)
       {
           k--;
           m=m+re[k].count;          
       } 
       if(m>n)
       {
           m=m-n-1;
           int h=abs(re[k].value-re[i].value);
           if(*min<h) *min=h;
           if(sum%n>1) //拥有左前点 
            {
                if(m==0) 
                {  
                    h=abs(re[k-1].value-re[i].value);
                    if(h>*min) *min=h;    
                }           
            }   
            if(sum%n!=0)  //拥有右后点 
            {
                 if(m==re[k].count)
                 {
                    h=abs(re[k+1].value-re[i].value);
                    if(h>*min) *min=h;   
                 }           
            }       
       }
}
void finddown(int *min,int sum,int i,int j)
{
       int  k=i,m=j;
       while(k<ce && m<n)
       {
           k++;
           m=m+re[k].count;          
       } 
       if(m>=n)
       {
           m=re[k].count-(m-n)-1;
           int h=abs(re[k].value-re[i].value);
           if(*min<h) *min=h;
           if(sum%n>1) //拥有前驱点 
            {
                if(m==0) 
                {  
                    h=abs(re[k-1].value-re[i].value);
                    if(h>*min) *min=h;    
                }           
            }   
            if(sum%n!=0)  //拥有后继点 
            {
                 if(m==re[k].count)
                 {
                    h=abs(re[k+1].value-re[i].value);
                    if(h>*min) *min=h;   
                 }           
            }       
       }
}
int main()
{
   int s=0;
   while(true)
   {
        int x,y,min;
        scanf("%d",&n);
        if(n==0) break;
        while(true)
        {
           scanf("%d %d",&y,&x);
           if(x==0 && y==0) break;
           re[front].count=x;
           re[front++].value=y;
           summax=summax+x;    
           ce++;       
        }   
        for(int i=0;i<front;i++)
        {
           int f=sum,t=0;
           for(int j=1;j<=re[i].count;j++)
           {

               min=0;
               sum++;
               int fh=sum-f-1;
               if(fh>n && t==0)
               {
                    int fs=re[i].count-n-1;
                    j=re[i].count-n;
                    sum=j+f;
                    t=1;
                    result[rear].count=result[rear].count+fs-fh+1;
                    continue;           
               }
               if(sum-n>0) findup(&min,sum,i,j);//上一层 
               if(sum%n>1 || sum%n==0) //拥有前驱点 
               {
                   if(j==1)
                   {  
                      int h=abs(re[i-1].value-re[i].value);
                      if(h>min) min=h;    
                   }          
               }   
               if(sum%n!=0)  //拥有后继点 
               {
                   if(j==re[i].count)
                   {
                      int h=abs(re[i+1].value-re[i].value);
                      if(h>min) min=h;   
                   }           
              }   
              if( summax-sum>=n) finddown(&min,sum,i,re[i].count-j);//下一层 
              if(s==0)
              {
                  result[rear].value=min;
                  result[rear].count=1; 
                  s=1;          
              }
              else
              {    
                 if(min==result[rear].value) result[rear].count++;
                 else 
                 {
                      result[++rear].value=min;
                      result[rear].count=1;
                 }
              }
           }       
        }
        printf("%d\n",n);
        for(int i=0;i<=rear;i++)
        printf("%d %d\n",result[i].value,result[i].count);      
        printf("0 0\n");  
        s=0;
        sum=0;
        summax=0;
        rear=0;
        front=0;
   }
   printf("0\n");
   system("pause");
   return 0;
}

