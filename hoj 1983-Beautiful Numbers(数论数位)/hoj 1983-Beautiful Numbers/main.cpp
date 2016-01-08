#include<cstdio>
#include<cmath>
#include<cstring>
#define MMOD 2520//2250是1到9的最小公倍数
__int64 __int64 dp[20][MMOD][50];
int num[20],temp;
int gs[MMOD];
void swap(int a,int b)
{
	int t=a;
	a=b;
	b=t;
}
int gcd(int a, int b)//最大公约数
{
    int g;
    if(b==0){
        g=a;
	}
    else {
        g=gcd(b,a%b);
    }
    return g;
}
int lcm(int a, int b)//最小公倍数
{
	if(a<b) swap(a,b);
	if(b==0) return a;
    return a*b/gcd(a,b);
}
void rec(__int64 __int64 a)
{
	temp=0;  
    while(a){  
        num[++temp]=a%10;  
        a=a/10;  
    } 
}
void init()//找到各个1到9的最小公倍数,共48种
{
	int i,j,k,l,cnt=0;  
    memset(dp,0xff,sizeof(dp));  
    gs[0]=0;  
    for (i=1;i<10;i*=2)  
        for (j=1;j<10;j*=3)  
            for (k=1;k<10;k*=5)  
                for (l=1;l<10;l*=7){  
                    gs[i*j*k*l]=++cnt;  
                } 
}
__int64 __int64 dfs(int i,int mod,int mark,bool flag){  
    int p, high;  
    __int64 __int64 ret;  
    if (i <= 0) return (mod % mark == 0);  
    if (!flag && ~dp[i][mod][gs[mark]]) return dp[i][mod][gs[mark]];  
    high=flag?num[i]:9;  
    ret=0;  
    for (p=0;p<=high;p++){  
        ret += dfs(i-1,(mod*10+p)%2520,lcm(mark,p),flag &&(p==high));  
    }
    if(!flag) dp[i][mod][gs[mark]]=ret;  
    return ret;  
}
__int64 __int64 calc(__int64 __int64 a){  
    rec(a);  
    return dfs(temp,0,1,true);  
}
int main()
{
	__int64 __int64 L, R;  
    init();   
    while(scanf("%I64d %I64d", &L, &R)!=0)
        printf("%I64d\n",calc(R)-calc(L-1));    
}