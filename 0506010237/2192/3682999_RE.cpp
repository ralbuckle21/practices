#include<iostream>
using namespace std;
int t,lena,lenb,lenc,lend;
int cs=1;
char a[220],b[220],c[220],d[220];
bool v[220];
void print(char bb[220][220],int m,int n){
   if(m==0 || n==0) return ;
   if(bb[m][n]=='3'){
       print(bb,m-1,n-1);   
       v[m]=true;            
   }     
   else if(bb[m][n]=='2') print(bb,m-1,n);
   else print(bb,m,n-1);
}
void lcs(){
    int cc[220][220];
    char bb[220][220];
    for(int i=0;i<lenc;i++) cc[i][0]=0;
    for(int j=0;j<lena;j++) cc[0][j]=0; 
    for(int i=1;i<lenc;i++){
        for(int j=1;j<lena;j++){
           if(c[i]==a[j]){
                cc[i][j]=cc[i-1][j-1]+1;
                bb[i][j]='3';             
            }        
            else if(cc[i-1][j]>cc[i][j-1]){
                cc[i][j]=cc[i-1][j]; 
                bb[i][j]='2';    
            }
            else{
                cc[i][j]=cc[i][j-1];    
                bb[i][j]='1';
            }
        }        
    }
    print(bb,lenc-1,lena-1);
}
int main()
{
     scanf("%d",&t);
     while(t--){
         memset(v,0,sizeof(v));
         scanf("%s %s %s",a+1,b,c+1);
         a[0]='0'; c[0]='0';
         lena=strlen(a); lenb=strlen(b); lenc=strlen(c),lend=0;
         lcs();
         for(int i=1;i<lenc;i++){
             if(!v[i]) d[lend++]=c[i];        
         }
         int i=0,j=0;
         while(i<lenb && j<lend){
              if(b[i]==d[j]){ i++; j++;}
              else  i++;             
         }
         printf("Data set %d: ",cs++);
         if(j==lend) printf("yes\n");
         else printf("no\n");
     }
     system("pause");
     return 0;
}
