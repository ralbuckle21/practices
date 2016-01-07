#include<iostream>
using namespace std;
long long sum;
int c[500020];
int n;
void merge(int left,int m,int right){
     int n1=m-left+1;
     int n2=right-m;
     int a[n1+2],b[n2+2];
     for(int i=0;i<n1;i++) a[i]=c[left+i];
     for(int j=0;j<n2;j++) b[j]=c[m+1+j];
     a[n1]=INT_MAX; 
     b[n2]=INT_MAX;
     int i=0,j=0;
     for(int k=left;k<=right;k++){
          if(a[i]<=b[j]){
                c[k]=a[i];
                if(left+i>k) sum+=left+i-k;
                i++;             
          }        
          else{
                 c[k]=b[j];
                 if(m+j+1>k) sum+=m+j+1-k;
                 j++;       
          } 
     }
}
void mergesort(int left,int right){
     if(left<right) {
        int m=(left+right)/2;
        mergesort(left,m);
        mergesort(m+1,right);
        merge(left,m,right);
     }
}
int main()
{
     while(true){
          scanf("%d",&n);
          if(n==0) break;
          for(int i=0;i<n;i++) scanf("%d",&c[i]);   
          sum=0;
          mergesort(0,n-1);
          cout<<sum<<endl;         
     }
     system("pause");
     return 0;
}
