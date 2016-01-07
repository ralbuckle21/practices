#include<iostream>
using namespace std;
int a[30000];
int c[30000];
int n,m;
int partion(int left,int right) {
    int key=a[left];
     while(left<right){
         while(left<right && a[right]>=key)right--;
         a[left]=a[right];
         while(left<right && a[left]<=key)left++;  
         a[right]=a[left];              
     }
     a[left]=key;
     return left;
}
int select(int low,int high,int k){
    int s=partion(low,high);
    if(k==s) return a[k];
    else if(k<s) return select(low,s-1,k);
    else return select(s+1,high,k);    
}
void getresult(){
     int j=1;
    for(int i=1;i<=n;i++){    
        while(c[j]==i){
             printf("%d\n",select(1,i,j));
             j++;
             if(j>m) return;               
        }    
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
