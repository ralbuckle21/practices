#include<iostream>
using namespace std;
int main()
{
     int a,b,sum;
     while(scanf("%d %d",&a,&b)!=EOF){
           sum=0;
           for(int i=1;i<=10;i++){
               sum+=a;
               if(sum>=0) sum=sum-a-b;        
           }              
           int v=2*a+sum;
           if(v>0 && v<b) cout<<2*a+sum<<endl;
           else cout<<"Deficit"<<endl;
     }
     system("pause");
     return 0;
}
