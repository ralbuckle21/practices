#include<cstdio>
long long a_b_Mod_c(long long a,long long b,long long c)
{
    int digit[64];                   
    int i,k;
	long long res=1;          
    i=0;
    while(b)
    {
        digit[i++]=b%2;
        b>>= 1;
    }
    for(k=i-1;k>=0;k--)
    {
        res=(res*res)%c;                 
        if(digit[k] == 1)
        {
            res=(res*a)%c;                  
        }
    }

    return res;
} 
int main()
{
	long long a,b;
	while(scanf("%lld %lld",&a,&b)!=EOF)
	{
		if(a%2) printf("0\n");
		else printf("%lld\n",a_b_Mod_c(a/2,b,a));
	}
}