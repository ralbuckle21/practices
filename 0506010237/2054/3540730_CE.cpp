#include<iostream>
using namespace std;
typedef struct
{
    int child[2];
    int cost;    
    int len;   
}node;
int sign[1000];
int n,start,best=10000000;
void f(node mg[1000],int sum,int s,int r,int t){
     if(sum>=best) return;
     if(t==n+1){
        if(sum<best) best=sum;
        return;          
     }
     for(int i=s;i<=r;i++){
          int x=r;
          for(int j=0;j<mg[sign[i]].len;j++)
               sign[++x]=mg[sign[i]].child[j];
          int temp=sign[i];
          sign[i]=sign[s];
          f(mg,sum+mg[temp].cost*t,s+1,x,t+1);
          sign[i]=temp;
     }        
}
int main()
{
     int a,b,i;
     while(true){
        scanf("%d %d",&n,&start);
        if(n==0)  break;
        node mg[n];
        for(i=0;i<n;i++){
            scanf("%d",&mg[i].cost);  
            mg[i].len=0;     
        }
        sign[0]=start-1;
        for(i=1;i<n;i++){
            scanf("%d %d",&a,&b);
            mg[a-1].child[mg[a-1].len]=b-1;
            mg[a-1].len++;    
        } 
        f(mg,0,0,0,1);
        printf("%d\n",best);  
        best=10000000;       
     }
    system("pause");
    return 0;
}


