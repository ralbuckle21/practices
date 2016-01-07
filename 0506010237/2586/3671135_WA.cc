#include<iostream>
using namespace std;
int main()
{
     int a,b,sum;
     while(scanf("%d %d",&a,&b)!=EOF){
           sum=0;
           for(int i=1;i<=5;i++){
               sum+=a;
               if(sum>=b) sum=sum-a-b;        
           }              
           sum=sum*2;
           sum = sum+2*a;
           if(2*a>3*b) sum=sum-b-a;
           if(sum>0) cout<<sum<<endl;
           else cout<<"Deficit"<<endl;
           cout<<sum<<endl;
     }
     system("pause");
     return 0;
}
