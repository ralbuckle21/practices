#include<iostream>
using namespace std;
const int base=1024*1024+10;
struct node{
    int v;
    int num;    
}list[base];
int flag[base];
char c[35][22];
int a[35],x[22];
int n,m,e,t,len,s,d;
int result[30];
void init(){
    memset(flag,-1,sizeof(flag));
    len=1; s=0; d=0;
}
void swap(int i,int j){
     node tem=list[i];
     list[i]=list[j];
     list[j]=tem;
}
void heap(int i){
       int lchild=2*i,rchild=2*i+1,mins=i;
       if(lchild<=len && list[lchild].v<list[mins].v)  mins=lchild;
       if(rchild<=len && list[rchild].v<list[mins].v)  mins=rchild;
       if(mins!=i){
           swap(list[i],list[mins]);
           heap(mins);              
       }
}
void inheap(node key){
     list[++len]=key;
     int i=len;
     while(i>1 && list[i/2].v>list[i].v){ 
             swap(list[i],list[i/2]);
             i=i/2;          
     }    
}
node getmin(){
    node mins=list[1];
    list[1]=list[len--];
    if(len>1) heap(1);
    return mins;  
}
int pri_bfs(){
    node front,rear;
    int temp;
    list[1].v=0; list[1].num=s; flag[s]=0;
    while(len){
         front=getmin(); temp=front.num; 
         if(front.num==d){ return front.v; }    
         for(int i=n-1;i>=0;i--){
              x[i]=temp & 1; 
              temp=temp>>1;
         }
         for(int i=0;i<m;i++){
              temp=0;
              for(int j=0;j<n;j++){
                   temp=temp*2;
                   switch(c[i][j]){
                       case 'N': temp+=x[j]; break;
                       case 'F': temp+=1-x[j]; break;
                      // case 'C': temp+=0; break;
                       case 'S': temp+=1; break;             
                   }        
              }
              if(flag[temp]!=-1 && flag[temp]<=front.v+a[i]) continue;
              flag[temp]=front.v+a[i];
              rear.num=temp; rear.v=front.v+a[i];
              inheap(rear);      
         }  
    }   
    return -1;
}
int main(){
    char tems[22],temd[22];
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&e);
        for(int i=0;i<m;i++) scanf("%s%d",c[i],&a[i]);        
        for(int i=0;i<e;i++){
             init();
             scanf("%s%s",tems,temd);
             for(int j=0;j<n;j++){
                 s=s*2+tems[j]-'0';
                 d=d*2+temd[j]-'0';
             }
             result[i]=pri_bfs();          
        }
        for(int i=0;i<e;i++){
            if(result[i]!=-1) printf("%d ",result[i]);
            else printf("NP ");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
