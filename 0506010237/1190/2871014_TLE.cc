#include<iostream>
using namespace std;
int n,m,bests=10000000;
void f(int r,int h,int x,int v,int s)
{
    if(s>=bests)
      return;
    if(x==0)
    {
        if(s<bests && v==n)
           bests=s;
        return;        
    }      
    int vmin=(x-1)*(x-1)*x*x/4;
    for(int i=x;i<r;i++)
    {
      for(int j=x;j<h;j++)
      {
           int t=i*i*j;
           if(v+t+vmin>n)
              break;      
           if(2*(n-v-t)/i>bests)
              continue;
           f(i,j,x-1,v+t,s+2*i*j);  
      }
      if(i*i*x+v+vmin>n)
        break;
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    int vmin=(m-1)*(m-1)*m*m/4;
    for(int i=m;;i++)
    {
      for(int j=m;;j++)
      {
           int t=i*i*j;
           if(t+vmin>n)
              break;      
           if(i*i+2*(n-t)/i>bests)
              continue;
           f(i,j,m-1,t,2*i*j+i*i);  
      }
      if(vmin+i*i*m>n)
         break;
    }
    if(bests==10000000)
       bests=0;
    printf("%d\n",bests);
    system("pause");
    return 0;
}
