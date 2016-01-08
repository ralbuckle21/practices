#include<cstdio>
#include<cmath>
#include<cstring>
__int64 xi,yi;
__int64 a,b,c,k;
void swap(__int64 a,__int64 b)
{
	__int64 t=a;
	a=b;
	b=t;
}
__int64 gcd(__int64 a,__int64 b)//最大公约数
{
    __int64 g,temp;
    if(b==0){
		xi=1;
		yi=0;
		return a;
	}
    g=gcd(b,a%b);	
	temp=xi;
	xi=yi;
	yi=temp-a/b*yi;
    return g;
}
int main()
{
	while(scanf("%ld %ld %ld %d",&a,&b,&c,&k)&&(a|b|c|k))
	{
		__int64 d=b-a;
		__int64 g=gcd(c,((__int64)1)<<k);
		__int64 ri;
		if(d%g!=0) 
		{
			printf("FOREVER\n");
			continue;
		}
		if(a==b) 
		{
			printf("0\n");
			continue;
		}
		xi*=d/g;
		ri=(((__int64)1)<<k)/g;
		xi=(xi%ri+ri)%ri;
		printf("%ld\n",xi);
	}
}