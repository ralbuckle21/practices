#include<iostream>
using namespace std;
char a[1000011];
int n;
int main(){
    char x;
    int c=0;
    scanf("%d",&n); getchar();
    for(int i=n-1;i>=0;i--){
         a[i]=getchar(); 
         while(a[i]==' ' || a[i]=='\n') a[i]=getchar();
         getchar(); x=getchar(); 
         a[i]=a[i]+x-'0';
    }
    for(int i=0;i<n;i++){
         a[i]+=c;
         if(a[i]>'9'){ c=1; a[i]-=10; }
         else c=0;       
    }
    while(c) a[n++]=c+'0';
    for(int i=n-1;i>=0;i--) putchar(a[i]);
    printf("\n");
    system("pause");
    return 0;
}
