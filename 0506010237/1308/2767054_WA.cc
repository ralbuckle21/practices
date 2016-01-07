#include<iostream>
using namespace std;
typedef struct
{
    int chu;
    int ru;        
}node;
node num[22];
int counts=1;
int dian,bian,chus,rus,dians;
int main()
{
    int n,m,sign;
    while(true)
    {
       scanf("%d %d",&n,&m);
       if(n==-1 && m==-1)
         break;   
       sign=0;
       bian=0;
       dian=0;
       chus=0;
       rus=0;   
       dians=0;
       for(int i=1;i<22;i++)
       {
           num[i].chu=num[i].ru=0;        
       }   
       while(true)
       {
          if(n==0 && m==0)
          {
             printf("Case %d is a tree.\n",counts++);
             sign=1;
             break;
          }
          if(n>dians)
            dians=n;
          if(m>dians)
            dians=m;
          if(num[n].chu==0 && num[n].ru==0)
              dian++;
          if(num[m].chu==0 && num[m].ru==0)
              dian++;
          bian++;
          num[n].chu=1+num[n].chu;
          num[m].ru=1+num[m].ru;        
          scanf("%d %d",&n,&m);
          if(n==0 && m==0)
            break;           
       }  
       if(sign==0)
       {
          if(dian!=bian+1)
            printf("Case %d is not a tree.\n",counts++);
          else
          {
             for(int i=1;i<=dians;i++)
             {
                  chus=num[i].chu+chus;
                  rus=num[i].ru+rus;  
                  if(num[i].ru>=2)
                  {
                       printf("Case %d is not a tree.\n",counts++);
                       chus=rus=0;      
                       break;        
                  } 
             }
             if(chus!=rus)
             {
                  printf("Case %d is not a tree.\n",counts++);        
             }
             else
             {
                  printf("Case %d is a tree.\n",counts++);
             }
          }            
       }
    }
    system("pause");
    return 0;
}
