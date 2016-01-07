#include<iostream>
#include<math.h>
using namespace std;
int n;
int parent[11],child[1000][11],result[1000],lens[1000],c=0,childx[11];
int len1,len2;
int maxs(int a,int b){
     return a>b?a:b;   
}
bool cmpxy(){
    int j=len2-1;
    for(int i=len1-1;i>=0;i--){
        if(parent[i]==childx[j]) j--;
        if(j<0) return true;   
        if(i<j) return false;     
    }    
    return false;
}
void output(){
       printf("%d\n",c);
       for(int i=0;i<c;i++){
             printf("%d + ",result[i]);
             for(int j=lens[i]-1;j>=0;j--) printf("%d",child[i][j]);
             printf(" = %d\n",n); 
       }   
}
int main()
{
    scanf("%d",&n);
    int h=n,t=0;
    while(h){
        h=h/10;
        t++;         
    }
    h=n-pow(10,t)/10;
    if(h<n/2) h=n/2;
    h=maxs(h,10);
    len1=0,len2=0;
    int x=h,y=n-x;
    while(x){
       parent[len1++]=x%10;
       x=x/10;
    }
    while(y){
        childx[len2++]=y%10;
        y=y/10;
    }
    while(len1==len2){
        h++;
        x=0;y=0;
        parent[x]++;                
        while(parent[x]==10){
               parent[x+1]=1+parent[x+1];
               parent[x]=0;
               x++;             
        }
        if(x==len1) len1++;
        childx[y]--;
        while(childx[y]==-1){
               childx[y]=9;
               y++;
               childx[y]--;                 
        }
        if(y+1==len2 && childx[y]==0) len2--;              
    }
    if(len1>len2){
        while(len2+1<len1) childx[len2++]=0;
        if(cmpxy()){ 
            result[c]=h;
            lens[c]=len2;
            for(int b=0;b<len2;b++) child[c][b]=childx[b];
            c++;    
        } 
    }
    for(int i=h+1;i<=n;i++){
        x=0;y=0;
        parent[x]++;                
        while(parent[x]==10){
               parent[x+1]=1+parent[x+1];
               parent[x]=0;
               x++;             
        }
        if(x==len1) len1++;
        childx[y]--;
        while(childx[y]==-1){
               childx[y]=9;
               y++;
               childx[y]--;                 
        }
        if(y+1==len2 && childx[y]==0) len2--;
        while(len2+1<len1) childx[len2++]=0;
        if(len1==len2) continue;
        if(cmpxy()){ 
             result[c]=i;
             lens[c]=len2;
             for(int b=0;b<len2;b++) child[c][b]=childx[b];
             c++;    
        }        
    }
    output();
    system("pause");
    return 0;
}
