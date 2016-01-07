#include<iostream>
using namespace std;
long long a[50];
int cs=1;
int t,n;
void init(){
     a[0]=0;a[1]=2;a[2]=3;
     for(int i=3;i<45;i++) a[i]=a[i-1]+a[i-2]; 
}
int main()
{
    init();
     scanf("%d",&t);
     while(t--){
         scanf("%d",&n);
         printf("Scenario #%d:\n",cs++);
         printf("%d\n\n",a[n]);
     }
     system("pause");
     return 0;
}
