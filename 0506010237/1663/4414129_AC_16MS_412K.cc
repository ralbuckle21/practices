#include<iostream>
using namespace std;
int t,x,y;
int main(){
    int s,r;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&x,&y);
        s=x-y;
        if(s==0 && y%2==0) r=y*2;                
        else if(s==0 && y%2==1) r=1+(y-1)*2;
        else if(s==2 && y%2==0) r=2+y*2;
        else if(s==2 && y%2==1) r=3+(y-1)*2;
        else r=-1;
        if(r==-1) printf("No Number\n");
        else printf("%d\n",r);
    }
    system("pause");
    return 0;
}
