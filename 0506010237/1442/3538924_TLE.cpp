#include<iostream>
using namespace std;
int a[30000];
int c[30000];
int n,m;
void insert(int k){
     int key=a[k],i=k-1;
     while(i>=1 && a[i]>key){
         a[i+1]=a[i];       
         i--;
     }
     i++;
     a[i]=key;
}
void getresult(){
     int j=1;
    for(int i=1;i<=n;i++){
        insert(i);       
        while(j<=m && c[j]==i){
             printf("%d\n",a[j]);
             j++;               
        }    
        if(j>m) return;
    }     
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    getresult();
    system("pause");
    return 0;
}
