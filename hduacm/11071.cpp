#include<stdio.h>
#include<string.h>
#include<maths.h>

int main()
{
	char a[50000],b[50000];
	int A[50000],B[50000];
	__int64 LenA,LenB,n,size;
	while(scanf("%s,%s",a,b)!=EOF)
	{
		size=1;
		LenA=strlen(a);
		LenB=strlen(b);
		if(a[LenA-1]=='-')
		{
			size*=-1;
			LenA--;
		}
		if(b[LenB]=='-')
		{
			size*=-1;
			LenB--;
		}
        n=LenA>LenB ?la:LenB;
    	for(i=0;i<LenA;i++)
           A[i]=a[i]-'0';
		 for(i=0;i<LenB;i++)
           B[i]=b[i]-'0';
		//a=mul(a,b,LenB);
		if(size='-')
		{
			n=strlen(a);
			a[n]=-;
		}
		pritnf("%s",a);
	}
	return 0;
}
mul(char  *pa, char  *pb, __int64 n) 
{
	char *a,*b,*c,*d;
   if (2<=n && zero(x) && zero(y)) 
   {
     k=n/2;
     b=pa+k;  
    // a=x/p;
     d=pb+k;
    // c=y/p;
     ac=mul(a, c, k);
     bd=mul(b, d, k);
     mix=mul(a-b, d-c, k);
     return (ac*p+(mix+ac+bd)*p+bd);
    } 
 else if (x==0||y==0)  return 0;
 else  x*y;
}

