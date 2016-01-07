#include<iostream>
#include<string>
using namespace std;
typedef struct
{
      int money;
      string c;  
}node;
node m[14];
int num[10],visit[10],value[1000];
char mg[10001];
void init()
{
     value[int('I')]=1;
     value[int('V')]=5;
     value[int('X')]=10;
     value[int('L')]=50;
     value[int('C')]=100;
     value[int('D')]=500;
     value[int('M')]=1000;
     m[0].c="M";m[0].money=1000;
     m[1].c="CM";m[1].money=900;
     m[2].c="D";m[2].money=500;
     m[3].c="CD";m[3].money=400;
     m[4].c="C";m[4].money=100;
     m[5].c="XC";m[5].money=90;
     m[6].c="L";m[6].money=50;
     m[7].c="XL";m[7].money=40;
     m[8].c="X";m[8].money=10;
     m[9].c="IX";m[9].money=9;
     m[10].c="V";m[10].money=5;
     m[11].c="IV";m[11].money=4;
     m[12].c="I";m[12].money=1;
     m[13].c="O";m[13].money=0;
}
void output(int sum)
{
     int j=0;
     if(sum==0)
       cout<<m[13].c;
     while(sum>0)
     {
         if(sum-m[j].money>=0)
         {
            cout<<m[j].c;
            sum=sum-m[j].money;
         }         
         else
           j++;
     }
     printf("\n");
}
int main()
{
    init();
    int sum1=0,sum=0,sign=0,i,t=0;
    for(i=0;i<10;i++)
       visit[i]=false;
    while(true)
    {
        scanf("%s",mg);
        if(strcmp(mg,"QUIT")==0)
        {
            printf("Bye\n");
            break;
        }
        if(strcmp(mg,"RESET")==0)
        {
           printf("Ready\n");                   
           for(i=0;i<10;i++)
             visit[i]=false;
           continue;                                          
        }
        sum=sum1=0;
        int n=strlen(mg);
        sign=0;
        t=1;
        i=2;
        while(i<n)
        {
             if(mg[i]=='+' || mg[i]=='-')
             {
                 if(sign==1)
                    sum=sum1+sum;
                 else if(sign==2)
                    sum=sum-sum1;
                 else
                    sum=sum1;
                 if(mg[i]=='+')
                   sign=1;
                 else 
                   sign=2;
                 t=1; 
                 i++;   
                 sum1=0;
                 continue;         
             }   
             if(mg[i]<='9' && mg[i]>='0')
             {
                  if(visit[mg[i]-'0']==false)
                  {
                     printf("Error\n");
                     break;
                  }
                  sum1=sum1+num[mg[i]-'0'];  
                  i++;
                  continue;       
             } 
             if(t==1)
             {
                  sum1=sum1+value[mg[i]]; 
                  t=0;    
             }
             else
             {
                 if((mg[i-1]=='I' && (mg[i]=='V' || mg[i]=='X')) || (mg[i-1]=='X' && (mg[i]=='L' || mg[i]=='C')) || (mg[i-1]=='C' && (mg[i]=='D' || mg[i]=='M')))
                    sum1=value[mg[i]]+sum1-value[mg[i-1]]*2;
                 else
                   sum1=value[mg[i]]+sum1;
                 t=1;
             } 
             i++;       
        }
        if(i==n)
        {
           if(sign==1)
             sum=sum+sum1;
           else if(sign==2)
             sum=sum-sum1;
           else
             sum=sum1;
           if(sum>10000 || sum<0)
              printf("Error\n");
           else
           {
              printf("%c%c",mg[0],mg[1]);
              output(sum);
              num[mg[0]-'0']=sum;
              visit[mg[0]-'0']=true;
           }        
        }
    }
    system("pause");
    return 0;
}
