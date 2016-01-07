#include<iostream>
using namespace std;
/* 0/1背包问题 但是要注意有条件约束*/
int n;
bool w[101][45010]={false};
int a[101]={0};
int b[101];
int maxs=45000; 
int main()
{
    int k;
    scanf("%d",&n);
    b[0]=0;
    for(int i=1;i<=n;i++){
         scanf("%d",&a[i]);
         b[i]=b[i-1]+ a[i];     
    }
    if(n==0){ cout<<0<<" "<<0<<endl; return 0;}
    if(n==1){ cout<<0<<" "<<a[1]<<endl; return 0;}
    w[0][0]=true;
    for(int i=1;i<=n;i++){ //放k个人所能形成的所有状态w[k][j] 
        k=n/2+1;
        if(k>i) k=i;
        for(int t=k;t>=1;t--){
            for(int j=a[i];j<=b[i];j++)
                if(w[t-1][j-a[i]])
                    w[t][j]=true;        
        }        
    }
    k=n/2;
    int x,y;
    for(int j=1;j<=b[n];j++){
         if(w[k][j] && maxs>abs(b[n]-2*j)){
               maxs=abs(b[n]-2*j);
               x=j;
               y=b[n]-j;
         }        
    }
    if(x>y){ int temp=x; x=y; y=temp;}
    cout<<x<<" "<<y<<endl;
    system("pause");
    return 0;
}
