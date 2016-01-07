#include<iostream>
using namespace std;
typedef struct
{
      int u;
      int v;
      int w;  
}node;
int n,c=1;
node num[1000000];
void qsort(int k)
{
     int i;
     for(int j=1;j<k;j++)
     {
           i=j-1;
           node key=num[j];
           while(i>=0 && num[i].w>key.w)
           {
               num[i+1]=num[i];   
               i--;   
           }       
           num[i+1]=key;
     }   
}
void kruskal()
{
    int vset[n],k=n-1,j=0,m1,m2,s1,s2;
    for(int i=0;i<n;i++)
       vset[i]=i;
    while(k)
    {
           m1=num[j].u;
           m2=num[j].v;
           s1=vset[m1];
           s2=vset[m2];
           if(s1!=s2)
           {
               printf("%c%c%c %d\n",char(m1+'A'),'-',char(m2+'A'),num[j].w);
               k--;
               for(int i=0;i<n;i++)
                   if(vset[i]==s2)
                      vset[i]=s1;          
           }    
           j++;
    }     
}
int main()
{
    int k=0,f,t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(int i=0;i<n;i++)
          for(int j=0;j<n;j++)
          {
             scanf("%d",&f);
             getchar();
             if(f>0)
             {
                num[k].u=i;
                num[k].v=j;
                num[k].w=f;
                k++;
             }
          }
       printf("Case %d:\n",c++); 
       qsort(k);
       kruskal();
    }
    system("pause");
    return 0;
}
