#include<iostream>
using namespace std;
int t,n;
int num[20000];
int cmp(const void *a,const void *b){
     return *(int *)b-*(int *)a;   
}
int main()
{
    scanf("%d",&t);
    while(t--){
          scanf("%d",&n);
          for(int i=0;i<n;i++) scanf("%d",&num[i]);
          qsort(num,n,sizeof(num[0]),cmp);
          int sum=0;
          for(int i=2;i<n;i=i+3) sum+=num[i]; 
          cout<<sum<<endl;          
    }
    system("pause");
    return 0;
}
