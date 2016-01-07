#include<iostream>
using namespace std;
const int maxh=10010;
const int maxw=82;
char g1[maxh][maxw];
char g2[maxw][maxh];
int next[10010];
int n,m;
void readdata(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",g1[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            g2[j][i]=g1[i][j];
}
int nexts(char p[],int len){
    next[0]=-1; 
    int k=-1,sum=1;
    for(int i=1;i<len;i++){
        while(k>=0 && p[k+1]!=p[i]) k=next[k];
        if(p[k+1]==p[i]) k=k+1;
        next[i]=k;
        if(k==-1) sum=i+1;     
    }    
    return sum;
}
int gcd(int a,int b){
     int r;
     while(b){
          r=a%b;
          a=b;
          b=r;         
     }   
     return a;
}
int lcm(int a,int b){ return a*b/gcd(a,b); }
int solve(){
    int cnt1=1,cnt2=1;
    for(int i=0;i<n;i++){
        cnt1=lcm(cnt1,nexts(g1[i],m));
        if(cnt1>=m){ cnt1=m; break; }
    }
    for(int i=0;i<m;i++){
        cnt2=lcm(cnt2,nexts(g2[i],n));  
        if(cnt2>=n){ cnt2=n; break; }
    }
    return cnt1*cnt2;
}
int main(){
    readdata();
    printf("%d\n",solve());
    system("pause");
    return 0;
}
