#include<iostream>
using namespace std;
char c[110];
bool d[110];
int n;
bool sign;
void find(bool visit[5],int k){
     int b=n-1,a;
     if(!sign) return ;
     memset(d,0,sizeof(d));
     for(int i=0;i<n;i++) if(c[i]>='p') d[i]=visit[c[i]-'p'];
     while(c[b]>'a') b--;  
     a=b+1;
     while(b>=0){
         if(c[b]>='p'){
              a--;
              d[a]=visit[c[b]-'p'];            
         }
         else if(c[b]=='N') d[a]=!d[a];     
         else if(c[b]=='K'){ d[a+1] = d[a+1] & d[a]; a++; }
         else if(c[b]=='A'){ d[a+1] = d[a+1] || d[a]; a++; }
         else if(c[b]=='C'){ d[a+1] = !d[a] || d[a+1]; a++; }
         else if(c[b]=='E'){
              if(d[a]==d[a+1]) d[a+1]=true;
              else d[a+1]=false;     
              a++;
         }
         b--;
     }
     if(!d[n-1]){ sign=false; return;}
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
           memset(visit,0,sizeof(visit));
           find(visit,0);        
           if(sign) printf("tautology\n");
           else printf("not\n");    
     }
     system("pause");
     return 0;
}
