#include<iostream>
using namespace std;
typedef struct node
{
      int a,b;// 左右界 
      node *lchild,*rchild; //左右孩子 
      int cover;  //颜色代号 
}node;
bool flag[32];
void init(node *&tree,int left,int right) //线段树初始化 
{
       int mid=(left+right)/2;
       tree=(node *)malloc(sizeof(node));
       tree->a=left;
       tree->b=right;
       tree->cover=1;
       if(right-left==1) return; //已经到了叶节点 
       init(tree->lchild,left,mid);
       init(tree->rchild,mid,right); 
}
void insert(node *tree,int s,int d,int c)//
{
    int m;
    if(tree->cover!=c)//颜色不一样 
    {
         m=(tree->a+tree->b)/2;
         if(tree->a==s && tree->b==d)
         {
             tree->cover=c;
             return;
         }
         else if(tree->cover>0) //先保留现场把值传给左右节点 
         {
              tree->lchild->cover=tree->cover;
              tree->rchild->cover=tree->cover;    
         }
         tree->cover=-1; //颜色是复合的 
         if(d<=m) insert(tree->lchild,s,d,c); //只需修改左节点时 
         else if(s>=m) insert(tree->rchild,s,d,c);//只需修改右节点时 
         else //左右都需修改 
         {
              insert(tree->lchild,s,m,c);
              insert(tree->rchild,m,d,c);     
         }
    }    
}
void count(node *tree,bool flag[100],int a,int b)//统计结果 
{
    if(a==tree->a && b==tree->b)
    {
         if(tree->cover>0) flag[tree->cover]=true;//此种颜色存在 
         else if(tree->cover==-1)
         {
              count(tree->lchild,flag,tree->lchild->a,tree->lchild->b);
              count(tree->rchild,flag,tree->rchild->a,tree->rchild->b);     
         }
    }
    else
    {
         int m=(tree->a+tree->b)/2; 
         if(b<=m)count(tree->lchild,flag,a,b);
         else if(a>=m)count(tree->rchild,flag,a,b);
         else
         {
               count(tree->lchild,flag,a,m);
               count(tree->rchild,flag,m,b);    
         } 
    }    
}
int main()
{
   int n,t,k,a,b,color,mins; 
   char c;
   node *tree;
   init(tree,1,100001);
   scanf("%d %d %d",&n,&t,&k);
   while(tree->rchild->a>n+1) tree=tree->lchild;
   while(k--)
   {
        getchar();
        scanf("%c ",&c);
        if(c=='C') 
        {
             scanf("%d %d %d",&a,&b,&color);
             if(a>b){int tmp=a;a=b;b=tmp;}
             insert(tree,a,b+1,color);           
        }
        else if(c=='P')
        {
             scanf("%d %d",&a,&b);
             if(a>b){int tmp=a;a=b;b=tmp;}
             memset(flag,0,t+1);
             mins=0;
             count(tree,flag,a,b+1);
             for(int i=1;i<=t;i++) if(flag[i])mins++; 
             printf("%d\n",mins);
        }     
   }
   system("pause");
   return 0;
}

