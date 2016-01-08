#include<stdio.h>
int a,b,e=0;
int n,k,set[50500];
int rank[50500];
int d,x,y;
void init()
{
	for(int i=0;i<n;i++){
        set[i]=i;
        rank[i]=0;
    }
}
long findset(int x){
    int y=x;
    if(set[x]==x) return x;
    else y=findset(set[x]);
    rank[x]=(rank[set[x]]+rank[x])%3;
    set[x]=y;
    return y;
}
void unions(int x,int y,int w){
    a=findset(x);
    b=findset(y);
    set[b]=a;
    rank[b]=(rank[x]-rank[y]+w+3)%3;
}
int main()
{
    scanf("%d %d",&n,&k);
    init();
    for(int i=0;i<k;i++){
        scanf("%d %d %d",&d,&x,&y);
        if(x>n||y>n) {e++; continue;}
        a=findset(x);
        b=findset(y);
        if(a==b){
            if(d==1&&rank[x]!=rank[y]){e++; continue;}
            if(d==2&&(rank[x]+1)%3!=rank[y]){e++; continue;}
        }
        unions(x,y,d-1);
    }
    printf("%d\n",e);
}