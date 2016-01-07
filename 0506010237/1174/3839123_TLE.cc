#include<iostream>
#include<stdio.h>
using namespace std;
int sign[13]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096};
typedef struct {
    int count;
    int index;    
}nodes;
nodes node[100000];
int a,b,n,len;
int cmp( const void *a , const void *b ){
    nodes *c = (nodes *)a;
    nodes *d = (nodes *)b;
    if(c->count != d->count) return d->count - c->count;
    else return d->index - c->index;
}
void out(int i){
    int p=a,x=0;
    char m[20];
    while(sign[p]<=node[i].index) p++;
    p--;
    int v=p-1;
    int k=node[i].index-sign[p];
    while(k>0){
        m[x]=char(k%2+'0'); 
        k=k/2;
        x++;          
    }   
    for(int j=x;j<=v;j++) m[j]='0'; 
    for(int j=v;j>=0;j--) printf("%c",m[j]);
    printf(" ");
}
void make(){
     int c=b,w=0;
     char mg[20];
     for(int i=1;i<=b;i++){
         mg[i]=getchar();
         while(mg[i]==' ' || mg[i]=='\n') mg[i]=getchar();
         if(mg[i]=='2'){ c=i; break;}     
    }
    if(c<a) return;
    if(c<b)b=c;
    while(mg[b]!='2'){
         for(int i=1;i<=a;i++) w=int(mg[i]-'0')+w*2;
         node[w].count++;
         for(int j=a+1;j<=b;j++){
              w=int(mg[j]-'0')+w*2;
              node[sign[j]+w].count++;    
         } 
         for(int i=2;i<=b;i++) mg[i-1]=mg[i];
         w=0; 
         mg[b]=getchar();
         while(mg[b]=='\n' || mg[b]==' ') mg[b]=getchar();
    } 
    int t=1;
    w=0;
    while(a+t<=b){
        for(int i=1;i<=a;i++) w=int(mg[i]-'0')+w*2;
        node[w].count++;
        for(int j=a+1;j<=b-t;j++){
            w=int(mg[j]-'0')+w*2;
            node[sign[j]+w].count++;    
        }
        for(int i=2;i<=b-t;i++) mg[i-1]=mg[i];
        w=0;t++;
    } 
    qsort(node,len,sizeof(node[0]),cmp);
    int s=0,i=0;
    while(i<len && s<n){
         if(node[i].count==0) break;
         printf("%d ",node[i].count);  
         out(i);
         s++;i++;
         while(i<len && node[i].count==node[i-1].count){
               out(i);
               i++;                                    
         }
         printf("\n");
    }     
}
int main()
{
         freopen("book.txt","r",stdin);
     freopen("bb1.txt","w",stdout);
    scanf("%d%d%d",&a,&b,&n);
    len=sign[b];
    for(int i=a+1;i<=b;i++) sign[i]=sign[i]-sign[a];
    sign[a]=0; len += sign[b]; 
    for(int i=0;i<len;i++) {
        node[i].count=0;
        node[i].index=i;     
    }
    make();
    //system("pause");
    return 0;
}
