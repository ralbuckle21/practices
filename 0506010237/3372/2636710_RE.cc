#include<iostream>
using namespace std;
int k=0,h=1;
int main()
{
    int n;
    while(scanf("%d",&n))
    {
          bool mg[n];
          int num[n];
          h=1;
          for(int i=0;i<n;i++)
          {
            mg[i]=false;
            num[i]=n;
          }
          int a=0,b=0;
          mg[0]=true;
         while(h<n)
          {
              b=(a+b+1)%n; 
              if(mg[b]==false)
              {
                 mg[b]=true;
                 h++; 
                 num[b]=(a+1)%n;              
              }     
              else
              {
                 if(num[b]==(a+1)%n)
                   break;    
              }
              a++; 
              a=a%n;           
          }  
          if(h==n)
            printf("%s\n","YES");
          else
            printf("%s\n","NO");                      
    }
    system("pause");
    return 0;
}
