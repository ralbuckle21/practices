#include<iostream>
using namespace std;
int main()
{
   int n,h,stone[10000],i,x,j;
   while(true)
   {
          scanf("%d",&n);
          if(n==0)
             break;
          h=0;
          for(i=0;i<n;i++)
          {
              scanf("%d",&x);
              if(x!=0)
                stone[h++]=x;
          }
          i=0;
          if(h==0)
            printf("0\n");
          else if(h%2)
            printf("1\n");
          else
             for(i=0;i<h;i++)
             {
                 if(stone[i])
                 {
                      for(j=i+1;j<h;j++)
                            if(stone[i]==stone[j])
                            {
                                 stone[i]=0;
                                 stone[j]=0;
                                 break;
                            }
                       if(j==h)
                       {
                           printf("1\n");
                            break;
                       }
                 } 
            }  
            if(i==h)
              printf("0\n");        
   }
   system("pause");
   return 0;
}
