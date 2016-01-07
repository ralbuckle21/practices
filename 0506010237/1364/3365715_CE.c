#include<stdio.h>
#define MAX 105
#define MAXINT 1000000000
int dis[MAX],n,m;
struct{
	int st,ed,val;
}edge[MAX];
bool check(){//看存在负圈不
	int i,k;
	for(i=0;i<=n;i++)dis[i]=MAXINT;
	for(k=0;k<n;k++){
		for(i=0;i<m;i++)
		   if(dis[edge[i].st]+edge[i].val<dis[edge[i].ed]){
			dis[edge[i].ed]=dis[edge[i].st]+edge[i].val;
		   }
	}
        for(i=0;i<m;i++) if(dis[edge[i].st]+edge[i].val<dis[edge[i].ed]) return false;
	return true;
}
int main()
{
	int i,j,k,val;
	char str[5];
	while(scanf("%d",&n)!=EOF && n){
		scanf("%d",&m);
		n++;//因为得生成v0
		for(k=0;k<m;k++){
			scanf("%d%d%s%d",&i,&j,str,&val);
			j=i+j+1;//全部下标加了一
			if(str[0]=='l'){	
				edge[k].st=i;
				edge[k].ed=j;
				edge[k].val=val-1;
			}
			else{
				edge[k].st=j;
				edge[k].ed=i;
				edge[k].val=-val-1;
			}
		}
		if(check())
			printf("successful conspiracy\n");
		else
			printf("lamentable kingdom\n");
	}
	return 0;
}
