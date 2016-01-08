#include <iostream>
using namespace std;
int m,n,i,j;
int a[1000];
int main(){
	scanf("%d",&m);
	a[0]=1;
	a[1]=2;
	for(i=2;i<50;i++)
		a[i]=a[i-1]+a[i-2];
	for(i=0;i<m;i++){
		scanf("%d",&n);
		printf("Scenario #%d:\n",i+1);
		printf("%d\n\n",a[n]);
	}
}