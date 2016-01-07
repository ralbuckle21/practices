#include<iostream>
using namespace std;
int n,k;
int num[1001]; 
int main()
{
    int s,t,r,i=0,x;
    scanf("%d %d",&n,&k);
    while(i<k){
         scanf("%d %d %d",&s,&t,&r);
         x=n/s;
         if(n%s!=0) x++;
         num[i]=x;
         while(x>t){
             x=x-t;
             num[i]+=r;           
         }       
         i++;
    }
    for(i=0;i<k;i++) printf("%d\n",num[i]);
    system("pause");
    return 0;
}
