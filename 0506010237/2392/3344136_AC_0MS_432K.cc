#include<iostream>
using namespace std;
struct node
{
     int c;
     int h;
     int a;
}block[402];
bool access[40002]={0};
int n,maxs=0;
int cmp(void const *a,void const *b)
{
     return (*(node *)a).a-(*(node *)b).a;   
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
         scanf("%d %d %d",&block[i].h,&block[i].a,&block[i].c);
    qsort(block,n,sizeof(block[0]),cmp);
    access[0]=1;
    for(int i=0;i<n;i++)
    {
       int t=maxs-100;
       if(t<0) t=0;
       int tmp=maxs;
       for(int j=maxs;j>=t;j--)
       {
           if(access[j])
           for(int h=1;h<=block[i].c;h++)
           {
                  int x=h*block[i].h+j;
                  if(x>block[i].a) break;
                  if(tmp<x) tmp=x;
                  access[x]=1;        
           }      
       }
       maxs=tmp;
    }
    printf("%d\n",maxs);
    system("pause");
    return 0;
}

