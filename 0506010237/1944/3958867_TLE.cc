#include<iostream>
using namespace std;
bool flag[1001];
int a[1001];
int c[10000][2];
int n,p;
void sign(int k){
    for(int i=1;i<=n;i++){
          a[i]=k++;
          if(a[i]>n) a[i]=a[i]%n;        
    }    
}
int cal(){
    int count=0;
    for(int i=1;i<=n;i++) 
        if(flag[i]) count++;
    return count;    
}
int main(){
    int sum=10000;
    scanf("%d%d",&n,&p);
    for(int i=0;i<p;i++) scanf("%d%d",&c[i][0],&c[i][1]);
    for(int i=1;i<=n;i++){
          sign(i); 
          memset(flag,0,sizeof(flag));
          for(int j=0;j<p;j++){
              int v1=a[c[j][0]],v2=a[c[j][1]];
              if(v1>v2){ int temp=v1; v1=v2; v2=temp;}
              for(int k=v1;k<v2;k++) flag[k]=true;      
          }       
          int v=cal();
          if(v<sum) sum=v;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
