#include<iostream>
using namespace std;
int a[4]={1,1,1,1};
int prim[4]={2,3,5,7};
int num[5843];
int n;
void init(){
    num[1]=1;
    for(int i=2;i<=5842;i++){
        for(int j=0;j<4;j++)
           if(num[a[j]]*prim[j]<=num[i-1]) a[j]++; 
        int min=2000000001;
        for(int j=0;j<4;j++)
            if(num[a[j]]*prim[j]<min)
              min=num[a[j]]*prim[j];  
        num[i]=min;
    } 
}
int main()
{
    init();
    while(true){
        scanf("%d",&n); 
        if(n==0) break;
        if(n%10==1 && n%100!=11) printf("The %dst humble number is %d.\n",n,num[n]);
        else if(n%10==2 && n%100!=12) printf("The %dnd humble number is %d.\n",n,num[n]);
        else if(n%10==3 && n%100!=13) printf("The %drd humble number is %d.\n",n,num[n]);
        else printf("The %dth humble number is %d.\n",n,num[n]);          
    }
    system("pause");
    return 0;
}
