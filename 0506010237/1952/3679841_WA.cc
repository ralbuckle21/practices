#include<iostream>
using namespace std;
struct{
    int slen; 
    int v[5000][2];  
}b[5001];
int n;
int num[5001];
int list(){
     int len=1,p,r,m;
     b[0].v[0][0]=INT_MAX; b[0].v[0][1]=1; b[0].slen=1;
     b[1].v[0][0]=num[0]; b[1].v[0][1]=1; b[1].slen=1;
     for(int i=1;i<n;i++){
         p=0; r=len;
         while(p<=r){
             int m=(p+r)/2;
             if(b[m].v[b[m].slen-1][0]>num[i])  p=m+1;
             else  r=m-1;         
         }    
         if(p>len){
               int j=0;
               b[p].slen=1;
               b[p].v[0][0]=num[i];
               b[p].v[0][1]=b[len].v[b[len].slen-1][1];
               while(num[i]>=b[len].v[j][0]) j++;
               j--;
               if(j>=0) b[p].v[0][1] -= b[len].v[j][1];
               len++;          
         } 
         else if(num[i]==b[p].v[b[p].slen-1][0]) continue; 
         else{
               int j=0;
               b[p].v[b[p].slen][0]=num[i];
               b[p].v[b[p].slen][1]=b[p-1].v[b[p-1].slen-1][1]+b[p].v[b[p].slen-1][1];
               while(num[i]>=b[p-1].v[j][0]) j++;
               j--;
               if(j>=0) b[p].v[b[p].slen][1] -= b[p-1].v[j][1];  
               b[p].slen++;
         }
     }
     return len;
}
int main()
{
     freopen("book.txt","r",stdin);
     freopen("bb.txt","w",stdout);
     scanf("%d",&n);
     for(int i=0;i<n;i++) scanf("%d",&num[i]);
     int len=list();
     cout<<len<<" "<<b[len].v[b[len].slen-1][1]<<endl;
     system("pause");
     return 0;
}
