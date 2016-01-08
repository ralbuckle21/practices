#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m[32],sum,now,i;
	bool flag;
	while(scanf("%d",&n)&&n!=0){
		memset(m,0,sizeof(m));
		sum=now=i=0;
		flag=false;
		for(i=1;i<=n;i++){
			scanf("%d",&m[i]);
			sum+=m[i];
		}
		if(sum%2==0){
			for(i=1;i<=n;i++){
				now+=m[i];
				if(now==sum/2){
					flag=true;
					break;
				}
				if(now>sum/2)
					break;
			}
		}
		if(flag) printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
		else printf("No equal partitioning.\n");
	}
}