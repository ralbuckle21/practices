#include <iostream>
using namespace std;
int n;
int a[20];
int f(int x){
    for(int i=0;i<n;i++) if(a[i]==x) return true;
    return false;   
}
int main()
{
    while(true){
        scanf("%d",&a[0]);
        if(a[0]==-1) break;
        n=1;        
        while(true){
             scanf("%d",&a[n]);
             if(a[n]==0) break;
             n++;            
        }
        int count=0;
        for(int i=0;i<n;i++)
            if(a[i]%2==0 && f(a[i]/2)) count++;
        printf("%d\n",count); 
    }
    system("pause");
    return 0;
}
