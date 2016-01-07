#include<iostream>
#include<string>
using namespace std;
char b[104][104];
int c[104][104];
char x[104],y[104];
char d[104];
int n,m,len;
void print(int m1,int n1){
   if(m1==0 || n1==0) return ;
   if(b[m1][n1]=='3'){
       print(m1-1,n1-1);
       d[len++]=x[m1];                
   }     
   else if(b[m1][n1]=='2') print(m1-1,n1);
   else print(m1,n1-1);
}
void lcs(){
    for(int i=1;i<=m;i++) c[i][0]=0;
    for(int j=1;j<=n;j++) c[0][j]=0; 
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
           if(x[i]==y[j]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='3';             
            }        
            else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j]; 
                b[i][j]='2';    
            }
            else{
                c[i][j]=c[i][j-1];    
                b[i][j]='1';
            }
        }        
    }
    len=0;
    print(m,n);
}
void dowork(){
    int i=1,h=0,j=1;
    while(i<=m){
         if(x[i]!=d[h]) printf("%c",x[i]);
         else{
              while(j<=n && h<len){
                   printf("%c",y[j]);
                   j++;
                   if(y[j-1]==d[h]){ h++; break; }     
              }     
         }    
         i++;  
         if(h==len) break;  
    }     
    while(i<=m){ printf("%c",x[i]); i++; }
    while(j<=n){ printf("%c",y[j]); j++; }
    printf("\n");
}
int main(){
   x[0]='0';y[0]='0';
   while(scanf("%s%s",x+1,y+1)!=EOF){
       m=strlen(x)-1; n=strlen(y)-1;
       lcs();
       dowork();
   }          
   system("pause");
   return 0;
}
