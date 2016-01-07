#include<iostream>
using namespace std;
typedef struct node
{
      int a,b;// 左右界 
      int cover;  //颜色代号 
}node;
node tree[310001];
bool flag[32]={0};
void init(int k,int left,int right) //线段树初始化 
{
       int mid=(left+right+1)/2;
       tree[k].a=left;
       tree[k].b=right;
       tree[k].cover=1;
       if(right-left==1) return; //已经到了叶节点 
       init(2*k,left,mid);
       init(2*k+1,mid,right); 
}
void insert(int k,int s,int d,int c)//
{
    int m;
    if(tree[k].cover!=c)//颜色不一样 
    {
         m=(tree[k].a+tree[k].b+1)/2;
         if(tree[k].a==s && tree[k].b==d)
         {
             tree[k].cover=c;
             return;
         }
         else if(tree[k].cover>0) //先保留现场把值传给左右节点 
         {
              tree[2*k].cover=tree[k].cover;
              tree[2*k+1].cover=tree[k].cover;    
         }
         tree[k].cover=-1; //颜色是复合的 
         if(d<=m) insert(2*k,s,d,c); //只需修改左节点时 
         else if(s>=m) insert(2*k+1,s,d,c);//只需修改右节点时 
         else //左右都需修改 
         {
              insert(2*k,s,m,c);
              insert(2*k+1,m,d,c);     
         }
    }    
}
void counts(int k,int a,int b)//统计结果 
{
    if(tree[k].cover>0 && a>=tree[k].a && b<=tree[k].b)//祖先节点是单色 
    {
          flag[tree[k].cover]=true;
          return;                 
    }
    if(a==tree[k].a && b==tree[k].b)//颜色是复合色 
    {
         counts(2*k,tree[2*k].a,tree[2*k].b);
         counts(2*k+1,tree[2*k+1].a,tree[2*k+1].b);     
    }
    else
    {
         int m=(tree[k].a+tree[k].b+1)/2; 
         if(b<=m)counts(2*k,a,b);
         else if(a>=m)counts(2*k+1,a,b);
         else
         {
               counts(2*k,a,m);
               counts(2*k+1,m,b);    
         } 
    }    
}
int main()
{
   int n,t,k,a,b,color,mins,i; 
   char c;
   scanf("%d %d %d",&n,&t,&k);
   init(1,1,n+1);
   while(k--)
   {
        getchar();
        scanf("%c ",&c);
        if(c=='C') 
        {
             scanf("%d %d %d",&a,&b,&color);
             if(a>b){int tmp=a;a=b;b=tmp;}
             insert(1,a,b+1,color);           
        }
        else
        {
             scanf("%d %d",&a,&b);
             if(a>b){int tmp=a;a=b;b=tmp;}
             mins=0;
             counts(1,a,b+1);
             for(i=1;i<=t;i++) if(flag[i]){ mins++; flag[i]=0;} 
             printf("%d\n",mins);
        }     
   }
   system("pause");
   return 0;
}

