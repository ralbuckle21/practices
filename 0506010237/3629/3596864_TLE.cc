#include<iostream>
using namespace std;
bool visit[100000]={0};
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
    while(true){
        for(int c=1;c<n;c++){
             while(visit[i]) i=(i+1)%k;
             visit[i]=1;
             j=0;
             while(j<p){
                        while(visit[i]) i=(i+1)%k;
                        i=(i+1)%k;
                        j++;
             }      
        }
        while(visit[i]) i=(i+1)%k;
        visit[i]=1;
        num[len++]=i;
        if(i==0) num[len-1]=k;
        if(len==m) break;
        j=0;
        while(j<p){
              while(visit[i]!=0) i=(i+1)%k;
              i=(i+1)%k;
              j++;
        }      
    }
    qsort(num,len,sizeof(num[0]),cmp);
    for(i=0;i<len;i++) printf("%d\n",num[i]);
    system("pause");
    return 0;
}
