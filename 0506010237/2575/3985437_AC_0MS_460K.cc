#include<iostream>
using namespace std;
int a[3003];
int n;
bool visit[3003];
int main(){
    int i;
    while(scanf("%d",&n)!=EOF){
        memset(visit,0,sizeof(visit));
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=1;i<n;i++){
            int v=abs(a[i]-a[i-1]);
            if(v>=n || visit[v]) break;
            visit[v]=true;
        }
        if(i==n) cout<<"Jolly"<<endl;
        else cout<<"Not jolly"<<endl;      
    }
    system("pause");
    return 0;
}
