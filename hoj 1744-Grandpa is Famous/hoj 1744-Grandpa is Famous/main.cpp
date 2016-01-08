#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXNUM 10005
int main()
{
	int m,n,player[MAXNUM],temp;
	while(scanf("%d %d",&m,&n)!=EOF&&m+n){
		int max1=0,max2=0;
		memset(player,0,sizeof(player));
		for(int i=0;i<m*n;i++){
			scanf("%d",&temp);
			player[temp]++;
			if(player[temp]>max1){
				max2=max1;
				max1=player[temp];
			}
			else if(player[temp]>max2&&player[temp]<max1)
				max2=player[temp];
		}
		for(int i=1;i<MAXNUM;i++){
			if(player[i]==max2)
				printf("%d ",i);
		}
		printf("\n");
	}
}