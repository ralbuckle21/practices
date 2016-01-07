#include<iostream>
using namespace std;
typedef struct{
     int id;
     int v;  
     int addv;  
}node;
node num[3000];
char s[30];
int n=0;/*
void heap(int k){
     int mins=k,lchild=2*k,rchild=2*k+1;
     if(lchild<=n && num[lchild].v<num[mins].v) mins=lchild;
     if(rchild<=n && num[rchild].v<num[mins].v) mins=rchild;
     if(mins!=k){
         int tem=num[k];
         num[k]=num[mins];
         num[mins]=tem;
         heap(mins);            
     }      
}
void buildheap(){
    for(int i=n/2;i>0;i--) heap(i);    
}
int getv(){
      int id=heap[1].id;
      heap[1].v+=heap[1].addv;
      heap(1);
      return id;  
}*/
int main()
{
     int a,b,k;
     while(true){
          scanf("%s",s);
          if(s[0]=='#') break;
          scanf("%d %d",&a,&b);
          num[++n].id=a; 
          num[n].addv=b; 
          num[n].v=b;           
     }
     scanf("%d",&k);
     while(k--){
          int mins=INT_MAX,u;
          for(int i=1;i<=n;i++)
               if(num[i].v<mins){
                    mins=num[i].v;
                    u=i;                  
               }
           printf("%d\n",num[u].id);        
           num[u].v+=num[u].addv;    
     }
     system("pause");
     return 0;
}
