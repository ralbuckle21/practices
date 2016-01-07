#include<iostream>
using namespace std;
int n=0,m=0;
struct{
     char c[20];
     int len;   
}d[10010],ch[50];
bool find(char a[20],char b[20],int len,int x,int y,bool sign,int ss){
     if(x==n) return true;
     if(a[x]==b[y]) return find(a,b,len,x+1,y+1,sign,ss);
     if(sign) return false;
     sign=true;
     if(ss==1) return find(a,b,len,x,y+1,sign,ss);           
     if(ss==2) return find(a,b,len,x+1,y,sign,ss);
     if(ss==3) return find(a,b,len,x+1,y+1,sign,ss);
}
int main()
{
     int j;
     while(true){
          scanf("%s",d[n].c);
          if(d[n].c[0]=='#') break;
          d[n].len=strlen(d[n].c);
          n++;        
     }
     while(true){
          scanf("%s",ch[m].c);
          if(ch[m].c[0]=='#') break;
          ch[m].len=strlen(ch[m].c);
          m++;            
     }
     for(int i=0;i<m;i++){
          for(j=0;j<n;j++){
               if(strcmp(ch[i].c,d[j].c)==0){
                     printf("%s is correct\n",d[j].c);
                     break;                             
               }        
          }        
          if(j==n){
               printf("%s:",ch[i].c);
               for(j=0;j<n;j++){
                   if(ch[i].len==d[j].len-1 && find(ch[i].c,d[j].c,ch[i].len,0,0,0,1))
                       printf(" %s",d[j].c);
                   else if(ch[i].len==d[j].len+1 && find(ch[i].c,d[j].c,ch[i].len,0,0,0,2))
                       printf(" %s",d[j].c);
                   else if(ch[i].len==d[j].len && find(ch[i].c,d[j].c,ch[i].len,0,0,0,3))
                       printf(" %s",d[j].c);                 
               }         
               printf("\n");
          }
     }
     system("pause");
     return 0;
}
