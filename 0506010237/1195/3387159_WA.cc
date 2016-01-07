/*一维时 	C[i] = a[i - 2^k + 1] + … + a[i]，k为i在二进制下末尾0的个数。
 	        2^k=x and (x xor (x-1)) 
 	       把这个问题转化成为求sum(1,b)-sum(1,a-1)
*/
#include<iostream>
using namespace std;
int cc[1025][1025]={0};
int n=1;
int lowbit(int x){
    return (x & (x ^ (x-1) ) );   
}
void init(int a){
     while(n<a) n=n*2;
     memset(cc,0,sizeof(cc));
}
void add(int a,int b,int c){
     for(int x=a;x<=n;x=lowbit(x)+x)
         for(int y=b;y<=n;y=lowbit(y)+y){
             cc[x][y]+=c;
            // if(cc[x][y]<0) cc[x][y]=0;   
         }
}
int count(int a,int b,int c,int d){
     int sum=0;
     for(int x=c;x>=a;x-=lowbit(x)){
         for(int y=d;y>=b;y-=lowbit(y)) sum+=cc[x][y];
         for(int y=b-1;y>=1;y-=lowbit(y)) sum-=cc[x][y];
     }
     for(int x=a-1;x>=1;x-=lowbit(x)){
         for(int y=d;y>=b;y-=lowbit(y)) sum-=cc[x][y];
         for(int y=b-1;y>=1;y-=lowbit(y)) sum+=cc[x][y];    
     }    
     return sum;  
}
int main()
{
    int sign,a,b,c,d;
    while(true){
         scanf("%d",&sign);
         if(sign==3) break;
         else if(sign==0){
              scanf("%d",&a);
              init(a);     
         }             
         else if(sign==1){
              scanf("%d %d %d",&a,&b,&c);
              add(a+1,b+1,c);     
         }
         else{
             scanf("%d %d %d %d",&a,&b,&c,&d);
             printf("%d\n",count(a+1,b+1,c+1,d+1));     
         }
    }
    system("pause");
    return 0;
}
