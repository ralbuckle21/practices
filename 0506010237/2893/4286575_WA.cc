/*   对于n*m的矩阵（n行m列），两个格局可以互相转换当且仅当，将空格用0代替以后：
     a. 若两格局中0的距离为偶数，两者的逆序数的奇偶性相同。
     b. 若两格局中0的距离为奇数，两者的逆序数的奇偶性相异。  */
#include<iostream>
using namespace std;
int n,m,len,nixu,dist,cn;
int c[1000010];
int p[1001][1001];
void merge(int left,int mid,int right){
     int n1=mid-left+1;
     int n2=right-mid;
     int a[n1+2],b[n2+2];
     for(int i=0;i<n1;i++) a[i]=c[left+i];
     for(int j=0;j<n2;j++) b[j]=c[mid+1+j];
     a[n1]=INT_MAX; 
     b[n2]=INT_MAX;
     int i=0,j=0;
     for(int k=left;k<=right;k++){
          if(a[i]<=b[j]){
              c[k]=a[i];
              i++;
          }
          else{
              c[k]=b[j];
              cn+=mid-i;
              j++; 
          } 
     }
}
void mergesort(int left,int right){
     if(left<right) {
           int mid=(left+right)/2;
           mergesort(left,mid);
           mergesort(mid+1,right);
           merge(left,mid,right);
     }
}
int main(){
    while(true){
         scanf("%d%d",&n,&m);
         if(n==0 && m==0) break; 
         len=0; cn=0;
         for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&p[i][j]);
                if(p[i][j]==0)  dist=n-i+m-j;
                else c[len++]=p[i][j];             
            }
         }      
         nixu=len-1;    
         mergesort(0,len-1);  
         if(dist%2==0 && nixu%2==cn%2) printf("YES\n");
         else if(dist%2==1 && nixu%2!=cn%2) printf("YES\n");
         else printf("NO\n");
    }
    system("PAUSE");
    return 0;
}
