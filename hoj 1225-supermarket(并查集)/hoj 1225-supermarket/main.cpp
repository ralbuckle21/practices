#include <stdio.h>
#include <algorithm>
#define M 10010
using namespace std;
int p[M];
struct node
{
 int val,ti;
}d[M];
int cmp(node a,node b)
{
 if(a.val==b.val)
  return a.ti>b.ti;
 else
  return a.val>b.val;
}
int Find(int x)
{
 if(p[x]!=x)
  p[x]=Find(p[x]);
 return p[x];
}
int main()
{
 int i,n;
 while(1==scanf("%i",&n))
 {
  int max=0;
  for(i=0;i<n;i++)
  {
   scanf("%d%d",&d[i].val,&d[i].ti);
   if(max<d[i].ti)
    max=d[i].ti;
  }
  for(i=0;i<=max;i++)
   p[i]=i;
  int ans=0;
  sort(d,d+n,cmp);
  for(i=0;i<n;i++)
  {
   int temp=Find(d[i].ti);
   if(temp>0)
   {
    ans+=d[i].val;
    p[temp]=temp-1;
   }
  }
  printf("%d\n",ans);
 }
 return 0;
}