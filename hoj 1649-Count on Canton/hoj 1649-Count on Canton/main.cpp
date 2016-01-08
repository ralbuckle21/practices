#include<iostream>
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		int l=0,x=1;
		while((l+x)<n){
			l+=x;
			x++;
		}
		int a,b;
		if(x%2==1){
			a=x-n+l+1;
			b=n-l;
		}
		else{
			b=x-n+l+1;
			a=n-l;
		}
		printf("TERM %d IS %d/%d\n",n,a,b);
	}
}