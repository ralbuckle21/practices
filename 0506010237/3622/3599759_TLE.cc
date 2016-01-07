#include<iostream>
using namespace std;
int n,m;
bool v[100000]={false};
long long int sum=0;
typedef struct{
     int c;
     int s;   
}cow;
cow cs[100000];
typedef struct{
     int c;
     int s;   
}greed;
greed g[100000];
int cmp1(const void *a,const void *b){
     return (*(cow *)a).s-(*(cow *)b).s;    
}
int cmp2(const void *a,const void *b){
     return (*(greed *)a).s-(*(greed *)b).s;   
}
int findmin(int a,int b){
     int min=1000000000,k=-1;
     while(b<m){
         if(!v[b]&& cs[a].c<=g[b].c && g[b].c<min){  
                min=g[b].c;
                k=b;        
         }
         b++;
     }  
     return k;
}
void find(){
     int r=m-1;
     for(int i=n-1;i>=0;i--){
         while(g[r].s>=cs[i].s) r--;
         int x=findmin(i,r+1);
         if(x==-1) cout<<"-1"<<endl;
         sum+=g[x].c;
         v[x]=true;        
     }     
     cout<<sum<<endl;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d %d",&cs[i].c,&cs[i].s);
    for(int i=0;i<m;i++) scanf("%d %d",&g[i].c,&g[i].s);
    qsort(cs,n,sizeof(cs[0]),cmp1);
    qsort(g,m,sizeof(g[0]),cmp2);
    find();
    system("pause");
    return 0;
}
