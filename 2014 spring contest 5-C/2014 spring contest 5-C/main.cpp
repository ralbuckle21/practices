#include<cstdio>
#include<algorithm>
using namespace std;

#define BUFSIZE 25

struct orders{
 int from;
 int to;
 int person;
 int value;
}order[BUFSIZE];

int station[BUFSIZE];

int m,n,l,result,best;

int dfs(int ordernum,int remain)
{
 if(ordernum == l){
  if(result>best)best = result;
  return 0;
 }
 
 remain -= order[ordernum].value;
 
 for(int i = order[ordernum].from;i < order[ordernum].to;i++)
  station[i]+=order[ordernum].person;
 
 bool flag = false;
 for(int i= order[ordernum].from;i < order[ordernum].to;i++)
  if(station[i]>m)flag=true;
 
 if(!flag){
  result += order[ordernum].value;
  dfs(ordernum+1,remain);
  result -= order[ordernum].value;
 }
 
 for(int i = order[ordernum].from;i < order[ordernum].to;i++)
  station[i]-=order[ordernum].person;
 
 if(remain+result>best)
  dfs(ordernum+1,remain);
  
 return 0;
}
bool mycomp(struct orders a,struct orders b)
{
 return a.value>b.value;
}
int main()
{ 
 scanf("%d%d%d",&m,&n,&l);
 while(!(m==0&&n==0&&l==0)){
  
  int remain = 0;
  for(int i=0;i<l;i++){
   scanf("%d%d%d",&order[i].from,&order[i].to,&order[i].person);  
   order[i].value = (order[i].to - order[i].from)*order[i].person;
   remain += order[i].value;
  }
  fill_n(station,BUFSIZE,0);
  sort(order,order+l,mycomp);
  best = 0;
  result = 0;
  dfs(0,remain);
  printf("%d\n",best);
  scanf("%d%d%d",&m,&n,&l);
 }
} 