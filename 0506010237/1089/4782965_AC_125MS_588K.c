#include <stdio.h>
#include <stdlib.h>

struct interval
{
	int begin,end;
}area[50001];


int cmp(const void *x,const void *y)
{
	//if( *(int *)x-*(int *)y )
		return *(int *)x-*(int *)y;
	//else
		//return *((int *)y+1)-*((int *)x+1);
} 

int main(){
	int n,i,start,over;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d",&area[i].begin,&area[i].end);
	qsort(area,n,sizeof(area[0]),cmp);
	start=area[0].begin;
	over=area[0].end;
	for(i=1;i<n;i++){
		if(area[i].begin>over){ 
			printf("%d %d\n",start,over);
			start=area[i].begin;
			over=area[i].end;
		}
		else{
			if(area[i].begin<=over&&area[i].end>over)
				over=area[i].end;
		}
	}
	printf("%d %d\n",start,over);
	return 0;
}
