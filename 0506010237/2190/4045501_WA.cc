#include<iostream>
using namespace std;
char mg[12];
int v[256];
int sum=0,sign;
void init(){
     for(int i=0;i<=9;i++) v[i+'0']=i;
     v['X']=10;     
}
int match(){
    for(int i=0;i<=9;i++)
         if((i*sign+sum)%11==0) return i;
    if(sign==1 && (10+sum)%11==0) return 10;
    return -1;     
}
int main(){
    init();
    scanf("%s",mg);
    for(int i=0;i<=9;i++)
        if(mg[i]!='?') sum=(sum+(10-i)*v[mg[i]])%11;
        else sign=10-i;
    int k=match();
    if(k==10) printf("x\n");
    else printf("%d\n",k);
   // system("pause");
    return 0;
}
