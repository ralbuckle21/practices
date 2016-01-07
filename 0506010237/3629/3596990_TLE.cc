#include<iostream>
using namespace std;
bool visit[100000]={0};
int next[100000];
int pre[100000];
int n,k,m,p;
int num[1000];
int len=0;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int main()
{
    int x=0,i=1,j;
    scanf("%d %d %d",&n,&k,&p);
    m=k/n;
    for(int h=0;h<k;h++) next[h]=h+1;
    next[k-1]=0;
    for(int h=1;h<k;h++) pre[h]=h-1;
    pre[0]=k-1;
    while(true){
        for(int c=1;c<n;c++){
             visit[i]=1;
             next[pre[i]]=next[i];
             pre[next[i]]=pre[i];
             i=next[i];
             j=0;
             while(j<p){
                 i=next[i];     
                 j++;
             }      
        }
        visit[i]=1;
        next[pre[i]]=next[i];
        pre[next[i]]=pre[i];
        num[len++]=i;
        i=next[i];
        if(i==0) num[len-1]=k;
        if(len==m) break;
        j=0;
        while(j<p){
              i=next[i];
              j++;
        }      
    }
    qsort(num,len,sizeof(num[0]),cmp);
    for(i=0;i<len;i++) printf("%d\n",num[i]);
    system("pause");
    return 0;
}
