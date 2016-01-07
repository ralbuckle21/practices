#include<iostream>
using namespace std;
int a[500001];
bool visit[10000001]={0};
void init(){
    a[0]=0;
    visit[0]=true;
    for(int i=1;i<=500000;i++){
        if(a[i-1]-i>0 && !visit[a[i-1]-i]){
             a[i]=a[i-1]-i;    
             visit[a[i]]=true;
        }
        else{
           a[i]=a[i-1]+i;
           visit[a[i]]=true;
        }   
    }
}
int main()
{
    init();
    int n;
    while(true){
        scanf("%d",&n);
        if(n==-1) break;
        printf("%d\n",a[n]);
    }
    system("pause");
    return 0;
}
