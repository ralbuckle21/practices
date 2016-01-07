#include<iostream>
using namespace std;
typedef struct
{
    int p;
    int rank;        
}node;
node mg[100001];
int n,m,t;
char h;
int find(int x,int &k)
{
     k=0;
     while(x!=mg[x].p)
     {
         k=k+mg[x].rank;
         x=mg[x].p;              
     }  
     return x;
}
int main()
{
    int a,b,num1,num2;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d%d",&n,&m);       
       for(int i=0;i<n;i++)
       {
           mg[i].rank=0;
           mg[i].p=i;
       }
       for(int i=0;i<m;i++)
       {
            getchar();
            scanf("%c%d%d",&h,&a,&b);
            if(h=='D')
            {
                  a=find(a,num1);
                  b=find(b,num2);  
                  if(a!=b)
                  {
                       if(num1<num2)
                       {
                           mg[a].p=b;
                           mg[a].rank=(num2-num1+1)%2; //我敌人的敌人是我朋友          
                       } 
                       else
                       {
                            mg[b].p=a;
                            mg[b].rank=(num1-num2+1)%2;    
                       }       
                  }
            }
            else if(h=='A')
            {
                 a=find(a,num1);
                 b=find(b,num2);
                 if(a!=b)
                    printf("Not sure yet.\n");
                 else
                 {
                     if((num1-num2)%2!=0)
                        printf("In different gangs.\n");
                     else
                         printf("In the same gang.\n");    
                 }
            }               
       }         
    } 
    system("pause");
    return 0;
}
