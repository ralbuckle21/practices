#include<iostream>
using namespace std;
int counts[101][60];
int sign;
void add(int temp[],int s)
{
    int i=0;
    int c=0;
    int third[60];
    for(int f=0;f<60;f++)
        third[f]=0; 
    while(i<59)
    {
          third[i]=temp[i]+counts[s][i]+c+third[i];
          c=third[i]/10;
          third[i]=third[i]%10;   
          i++;          
    }  
    third[i]=c;  
    for(i=0;i<60;i++)
       counts[s][i]=third[i];
}
void add1(int s1,int s2)
{
    int i=0;
    int c=0;
    int third[60];
    for(int f=0;f<60;f++)
        third[f]=0; 
    while(i<59)
    {
          third[i]=counts[s1][i]+counts[s2][i]+c+third[i];
          c=third[i]/10;
          third[i]=third[i]%10;   
          i++;          
    }  
    third[i]=c;  
    for(i=0;i<60;i++)
       counts[s2][i]=third[i];
}
void mul(int s1,int s2,int n)
{
    int third[119];
    int g=1;
    for(int f=0;f<120;f++)
       third[f]=0;
    int w=0;
   for(int i=0;i<60;i++)
   {
          for(int j=0;j<60;j++)
            {
                  int k=counts[s1][i]*counts[s2][j];
                  w=(k%10+third[j+i])/10+k/10;
                   third[j+i]=(k%10+third[j+i])%10;
                   while(w)
                   {
                        third[j+i+g]=(w+third[j+i+g]);
                        w=third[j+i+g]/10;
                        third[j+i+g]=third[j+i+g]%10;
                     g++;
                   }
                   g=1;
            }
   }  
   int i=119; 
    add(third,n); 
}
void countnum(int n)
{
   if(n<=sign)
      return; 
   else
   {
       sign=n;
      int m=0;
      int k=n-2;
      for(int i=4;i<=k;i+=2) 
      {
           mul((i-2)/2,(n-i)/2,n/2);
      }         
      add1((n-2)/2,n/2);
      add1((n-2)/2,n/2); 
    }       
}
int main()
{
    int n;
    for(int i=0;i<101;i++)
       for(int j=0;j<60;j++)
          counts[i][j]=0;
     counts[1][0]=1;
     for(int j=2;j<=100;j++)
          countnum(2*j);   
    while(true)
    {
           cin>>n;
           if(n==-1)
             break;
           countnum(2*n);
           int i=59;
           while(true)
           {
               if(counts[n][i]==0)
                  i--; 
                else
                  break;  
                if(i<=0)
                   break; 
           }    
           while(i>=0)
           {
               cout<<counts[n][i];
               i--;    
           }     
           cout<<endl;
    }
    return 0;
}