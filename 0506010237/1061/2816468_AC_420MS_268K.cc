#include<iostream>
using namespace std;
int main()
{
   unsigned long x,y,m,n,l;
   scanf("%ld %ld %ld %ld %ld",&x,&y,&m,&n,&l);
   if (m==n) 
      printf("Impossible\n");
   else
   { 
      if(m>n)
      {
              m=m-n;
              x=(y-x+l)%l;
      }
      else 
      {
           m=n-m;
           x=(x-y+l)%l;
      }  
      n=x/m;
      x=x%m;
      y=x;                     
      while(1)
      { 
              if(y==0) 
              {
                       printf("%ld\n",n);
                       break;
              } 
              n=n+(y+l)/m;
              y=(y+l)%m;                                    
              if(y==x) 
              {
                       printf("Impossible\n");
                       break;
              } 
      }                                                           
    }                                     
    system("pause");
    return 0;
}
         
