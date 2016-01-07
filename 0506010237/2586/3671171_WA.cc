#include<iostream>
using namespace std;
int main()
{
     int s,d,sum;
     while(scanf("%d %d",&s,&d)!=EOF){
           sum=0;
           if(4*s<d) sum=10*s-2*d;
           else if(3*s<2*d) sum=8*s-4*d;
           else if(2*s<3*d) sum=6*s-6*d;
           else sum=3*s-9*d;
           if(sum>0) cout<<sum<<endl;
           else cout<<"Deficit"<<endl;       
     }
     system("pause");
     return 0;
}
