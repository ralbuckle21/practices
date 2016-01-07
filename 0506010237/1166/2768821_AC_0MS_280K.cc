#include<iostream>
using namespace std;
int num[9];
int s[9];
bool good()
{
     int k=(num[0]+s[0]+s[1]+s[3])%4;
     if(k!=0)
       return 0;
     k=(num[1]+s[0]+s[1]+s[2]+s[4])%4;     
     if(k!=0)
       return 0;
     k=(num[2]+s[1]+s[2]+s[5])%4;     
     if(k!=0)
       return 0;
     k=(num[3]+s[0]+s[3]+s[4]+s[6])%4;     
     if(k!=0)
       return 0;
     k=(num[4]+s[0]+s[2]+s[6]+s[4]+s[8])%4;     
     if(k!=0)
       return 0;
     k=(num[5]+s[2]+s[4]+s[5]+s[8])%4;     
     if(k!=0)
       return 0;
     k=(num[6]+s[3]+s[6]+s[7])%4;     
     if(k!=0)
       return 0;
     k=(num[7]+s[4]+s[6]+s[7]+s[8])%4;     
     if(k!=0)
       return 0;
     k=(num[8]+s[5]+s[7]+s[8])%4;     
     if(k!=0)
       return 0;
     return 1;
}
void getresult()
{
    for(s[0]=0;s[0]<4;s[0]++)
    for(s[1]=0;s[1]<4;s[1]++)
    for(s[2]=0;s[2]<4;s[2]++)
    for(s[3]=0;s[3]<4;s[3]++)
    for(s[4]=0;s[4]<4;s[4]++)
    for(s[5]=0;s[5]<4;s[5]++)
    for(s[6]=0;s[6]<4;s[6]++)
    for(s[7]=0;s[7]<4;s[7]++)
    for(s[8]=0;s[8]<4;s[8]++)
    {
         if(good())
         {
             for(int i=0;i<9;i++)
               while(s[i]!=0)
               {
                 printf("%d ",i+1);
                 s[i]--;
               }
             printf("\n");     
             return;                      
         }        
    }
}
int main()
{
    for(int i=0;i<9;i++)
       scanf("%d",&num[i]);
    getresult();
    system("pause");
    return 0;
}
