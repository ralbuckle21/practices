#include<iostream>
using namespace std;
int sign[13]={0,2,4,8,16,32,64,128,256,512,1024,2048,4096};
typedef struct {
    int count;
    int index;    
}nodes;
nodes node[100000];
void out(int i,int a){
    int p=a,x=0;
    char m[13];
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
int cmp( const void *a , const void *b ){
    nodes *c = (nodes *)a;
    nodes *d = (nodes *)b;
    if(c->count != d->count) return d->count - c->count;
    else return d->index - c->index;
}
int main()
{
    int a,b,k=1,l,l1,n,w=0,i,j;
    scanf("%d%d%d",&a,&b,&n);
    l=sign[b];l1=sign[a];
    char mg[13];
    for(int i=a+1;i<=b;i++) sign[i]=sign[i]-sign[a];
    sign[a]=0;
    l=sign[b]+l;
    for(int i=0;i<l;i++) {
        node[i].count=0;
        node[i].index=sign[a]+i;     
    }
   mg[1]=getchar();
   while(mg[1]<'0' || mg[1]>'2') mg[1]=getchar();
   for(i=2;i<=b;i++){
      mg[i]=getchar();
      if(mg[i]=='2') b=i;      
   }
   if(b>a){
   while(mg[b]!='2'){
        for(i=1;i<=a;i++) w=int(mg[i]-'0')+w*2;
        node[w].count++;  
        for(j=a+1;j<=b;j++){
            w=int(mg[j]-'0')+w*2;
            node[sign[j]+w].count++;     
        } 
        for(i=2;i<=b;i++) mg[i-1]=mg[i];
        w=0; 
        mg[b]=getchar();
        if(mg[b]=='\n') mg[b]=getchar();
   } 
   int t=1;
   while(a+t<=b){
       for(i=t;i<=a+t-1;i++) w=int(mg[i]-'0')+w*2;
       node[w].count++;
       for(j=a+1;j<=b-t;j++){
          w=int(mg[j]-'0')+w*2;
          node[sign[j]+w].count++;    
       }
       w=0;
       t++;
   } 
    qsort(node,l,sizeof(node[0]),cmp);
    int s=0;
    i=0;
    while(i<l && s<n)
    {
         if(node[i].count==0) break;
         printf("%d ",node[i].count);  
         out(i,a);
         s++;     
         i++;
         while(i<l && node[i].count==node[i-1].count){
               out(i,a);
               i++;                                    
         }
         printf("\n");
    } 
    }
    system("pause");
    return 0;
}

