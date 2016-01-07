#include<iostream>
using namespace std;
typedef struct{
      int u;
      int v;
      int w;
      bool visit;
}node;
int n,m,sum=0;
node num[15000];
void qsort(int k){
     for(int j=1;j<k;j++){
           int i=j-1;
           node key=num[j];
           while(i>=0 && num[i].w>key.w){
               num[i+1]=num[i];   
               i--;   
           }       
           num[i+1]=key;
     }   
}
void kruskal(){
    int vset[n],k=n-1,j=0,m1,m2,s1,s2;
    for(int i=0;i<n;i++) vset[i]=i;
    while(k){
           m1=num[j].u;m2=num[j].v;
           s1=vset[m1];s2=vset[m2];
           if(s1!=s2){
               num[j].visit=true;
               if(num[j].w>sum) sum=num[j].w;
               k--;
               for(int i=0;i<n;i++)
                   if(vset[i]==s2) vset[i]=s1; 
           }    
           j++;
    }     
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d%d",&num[i].u,&num[i].v,&num[i].w);
        num[i].visit=false;
    }    
    qsort(m);
    kruskal();
    printf("%d\n%d\n",sum,n-1);
    for(int i=0;i<m;i++){
         if(num[i].visit) printf("%d %d\n",num[i].u,num[i].v);        
    }
    system("pause");
    return 0;
}

