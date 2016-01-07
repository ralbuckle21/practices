#include<iostream>
using namespace std;
int n,len=0,num[30];
int getbase(int base){
     int key=base/11,k=base%11;
     if(k==10) return 0;
     return 10*key+k;   
}
int cmp( const void *a ,const void *b)
{
     return *(int *)a - *(int *)b;
}
int output(){
     qsort(num,len,sizeof(num[0]),cmp);
     int j=0;
     for(int i=1;i<len;i++) if(num[i]!=num[j]) num[++j]=num[i];
     printf("%d\n",j+1);
     for(int i=0;i<=j;i++){
            int x=0,t=num[i];
            while(t){
                 x++;
                 t=t/10; 
            }        
            if(x==1) continue;
            x--;
            printf("%d + ",num[i]);
            cout.width(x);
            cout.fill('0');
            cout<<n-num[i];
            printf(" = %d\n",n);    
     }     
}
int main()
{
   // while(true){
    scanf("%d",&n);
    int base=1,x,y,key,k;
    while(base<=n){
          key=n/base;
          y=n%base;
          x=getbase(key)*base;
          if(x!=0 && y%2==0) num[len++]=x+y/2;
          if(base!=1){
             key--;
             y=base+y;
             x=getbase(key)*base;
             if(x!=0 && y%2==0) num[len++]=x+y/2; 
          }
          base=base*10;               
    }
    if(len>0) output();
    else printf("0\n");
   // len=0;
   // }
    system("pause");
    return 0;
}
