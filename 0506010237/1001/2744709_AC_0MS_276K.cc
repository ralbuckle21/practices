#include<iostream>
using namespace std;
int mg[130];
int sign;
void shengfa(int num)
{
    int g=1,third[130];
    for(int f=0;f<130;f++)
       third[f]=0;
    for(int j=0;j<125;j++)
    {
          int k=mg[j]*num;
          int w=(k%10+third[j])/10+k/10;
          third[j]=(k%10+third[j])%10;
          while(w)
          {
               third[j+g]=(w+third[j+g]);
               w=third[j+g]/10;
               third[j+g]=third[j+g]%10;
               g++;
          }
          g=1;
    }
    for(int i=0;i<130;i++)
       mg[i]=third[i];
}
void output(int sign)
{
    int j=0;
    while(true)
    {
         if(mg[j]==0 && j<sign)
           j++;
         else
           break;
         if(j>=129)
           break;           
    }
    int i=129;
    while(true)
    {
          if(i==sign-1)
              break;             
          if(mg[i]==0)
              i--; 
          else
             break;  
          if(i<=0)
            break; 
    }    
    while(i>=j)
    {
        if(i==sign-1)
           printf(".");
        printf("%d",mg[i]);
           i--;    
    }     
    printf("\n");
}
int main()
{
    char c;
    int num,k;
    while((c=getchar())!=EOF)
    {
         num=0;
         int h=4;
         for(int i=0;i<130;i++)
            mg[i]=0;
          for(int i=1;i<=5;i++)
          {
                if(c=='.')
                  sign=i;
                else
                { 
                  num=num*10+int(c-'0');
                  mg[h--]=int(c-'0');  
                }
                c=getchar();        
          } 
          if(c=='.')
            sign=6;
          else
          { 
               num=num*10+int(c-'0');
                  mg[h--]=int(c-'0');  
          } 
          sign=6-sign; 
          scanf("%d",&k);
          sign=k*sign;
          for(int i=1;i<k;i++)
             shengfa(num);
          output(sign);
          getchar();            
    }
    system("pause");
    return 0;
}
