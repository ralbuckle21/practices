#include<iostream>
using namespace std;
long long int f(int m,int n){
   if(m<0) return 0;
   else if(m==1 || n==1) return 1;
   else return f(m,n-1)+f(m-n,n);
}
int main()
{
   int m,n;
   while(true){
        scanf("%d %d",&m,&n);
        if(n==0 && m==0) break;
        cout<<f(m-n,n)<<endl;
   }
   system("pause");
   return 0;
}

