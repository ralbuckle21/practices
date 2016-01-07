#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define NMAX 500005
struct city{
	int a;
	int num;
};
/*int cmp ( const void *a , const void *b ) 
{ 
	const city *x=(const city *)a;
	const city *y=(const city *)b;
	if((x->a)>(y->a)) return 0;
	return 1;
}*/
bool cmp(city x,city y){
	return x.a>y.a;
}
int main()
{
	int n,b;
	while(scanf("%d %d",&n,&b)&&n>0){
		city *c=new city[n];
		for(int i=0;i<n;i++){
			scanf("%d",&c[i].a);
			c[i].num=1;
		}
		b-=n;
		//qsort(c,n,sizeof(city),cmp);
		sort(c,c+n,cmp);
		while(b){
			b--;
			c[0].a*=c[0].num;
			c[0].num++;
			c[0].a/=c[0].num;
			if(b<10||b%27==0)
				sort(c,c+n,cmp);
			//qsort(c,n,sizeof(city),cmp);
		}
		cout<<c[0].a<<endl;
	}
}