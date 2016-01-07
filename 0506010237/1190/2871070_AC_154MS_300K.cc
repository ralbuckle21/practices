#include<iostream>
using namespace std;
int n,m,bests=10000000;
int maxr=25,maxv[26][26];
void set()
{
	int i,j;
	for(i=0;i<=maxr;i++)
	{
		maxv[i][0]=0;
		maxv[0][i]=0;
	}
	for(i=1;i<=maxr;i++)
		for(j=1;j<=maxr;j++)
		{
			maxv[i][j]=maxv[i-1][j-1]+i*i*j;
		}
}
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
           if(maxv[i-1][j-1]+v+t<n)
              continue;   
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
    set();
    for(int i=m;i<26;i++)
    {
      for(int j=m;j<26;j++)
      {
           int t=i*i*j;
           if(t+vmin>n)
              break;   
           if(maxv[i-1][j-1]+t<n)
              continue;   
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
