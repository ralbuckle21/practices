#include<iostream>
using namespace std;
int n;
int c[32005];
int r[15005];
int lowbit(int x){
    return (x & (x^(x-1)));    
}
int sum(int x){
   int result=0;
   while(x>0){   
       result=result+c[x];
       x=x-lowbit(x);
   }
   return result;
}
void modify(int p){
    while(p<=32000) {
        c[p]=c[p]+1;
        p=p+lowbit(p);           
    }    
}
int main()
{
    int x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%d %d",&x,&y);
         r[sum(x)]++;
         modify(x);        
    }
    for(int i=0;i<n;i++) printf("%d\n",r[i]);
    system("pause");
    return 0;   
}

