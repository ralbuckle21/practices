#include<iostream>
using namespace std;
int value[26]={2,5,4,4,1,6,5,5,1,7,1,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
struct node{
     int sign;
     int v[26];   
     int len;
}c[40000],key,d;
int n=0,result=0;
char mg[10];
int cmp(const void *a,const void *b){
    return (*(node *)a).sign-(*(node *)b).sign;    
}
void cy(int x,int y){
     d.sign=c[x].sign+c[y].sign;
     for(int i=0;i<26;i++)  d.v[i]=c[x].v[i]+c[y].v[i];     
}
bool match(node a){
    for(int i=0;i<26;i++)
        if(a.v[i]>key.v[i]) return false;
    return true; 
}
int main(){
    scanf("%s",mg);
    key.len=strlen(mg);
    for(int i=0;i<key.len;i++){
        key.v[mg[i]-'a']++;
        key.sign+=value[mg[i]-'a'];        
    }
    while(true){
         scanf("%s",mg);
         if(mg[0]=='.') break;
         c[n].len=strlen(mg);
         for(int i=0;i<c[n].len;i++){
               c[n].v[mg[i]-'a']++;
               c[n].sign+=value[mg[i]-'a'];        
         }            
         n++;
    }
    for(int i=0;i<n;i++){
         if(c[i].len>key.len || c[i].sign>key.sign){
               c[i].sign=10000;
               continue;                    
         }        
         if(!match(c[i])) c[i].sign=10000;
         else if(c[i].sign>result) result=c[i].sign;
    }
    qsort(c,n,sizeof(c[0]),cmp);
    for(int i=0;i<n;i++){
         if(c[i].sign>key.sign) break;
         for(int j=i+1;j<n;j++){
              if(c[i].sign+c[j].sign>key.sign) break;
              if(c[i].len+c[j].len>key.len) continue;
              cy(i,j);
              if(match(d) && d.sign>result) result=d.sign;        
         }        
    }
    printf("%d\n",result);
    system("pause");
    return 0;
}
