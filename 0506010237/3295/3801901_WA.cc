#include<iostream>
using namespace std;
char c[110];
int n;
bool sign;
void find(bool visit[5],int k){
     if(!sign) return ;
     bool a=true,b=true;
     int x=0;
     for(int i=0;i<n;i++){
         if(c[i]>='p' && c[i]<='t'){
               if(x==0){
                    a=visit[c[i]-'p'];
                    x++;
               }
               else{
                     b=visit[c[i]-'p'];
                     x++;
               }            
         }       
         else if(c[i]=='N'){
              if(x==1) a=!a;
              else b=!b;              
         }
         else if(c[i]=='K'){
              a = a & b;
              x=1;     
         }
         else if(c[i]=='A'){
              a = a || b;
              x=1;     
         }
         else if(c[i]=='C'){
              a = !a || b;
              x=1;     
         }
         else if(c[i]=='E'){
              if(a==b) a=true;
              else a=false;
              x=1;     
         }
     }    
     if(!a){
         sign=false;
         return;       
     }
     k++;
     if(k==32) return;
     int y=k,i=0;
     while(y){
          visit[i]=y%2;
          y=y/2;
          i++;         
     }
     find(visit,k);
}
int main()
{
     bool visit[5];
     while(true){
           scanf("%s",c);
           if(c[0]=='0') break;
           n=strlen(c); sign=true;
           int i=0,j=n-1;
           while(i<j){
               char temp=c[i]; c[i]=c[j]; c[j]=temp;
               i++; j--;           
           }
           memset(visit,0,sizeof(visit));
           find(visit,0);        
           if(sign) printf("tautology\n");
           else printf("not\n");    
     }
     system("pause");
     return 0;
}
