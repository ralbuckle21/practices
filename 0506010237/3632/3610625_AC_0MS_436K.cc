#include<iostream>
using namespace std;
int a,b,w;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--){
         scanf("%d",&n);
         a=10000000;
         b=0;
         for(int i=0;i<n;i++){
                 scanf("%d",&w);
                 if(w<a) a=w;
                 if(w>b) b=w;        
         }    
         cout<<(b-a)*2<<endl;        
    }            
    system("pause");
    return 0;
}
