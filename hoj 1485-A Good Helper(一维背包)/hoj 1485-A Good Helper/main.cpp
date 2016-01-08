/*#include<iostream>
using namespace std;
#define MAX 205
#define MAXN 2005
int A,C,n,m[MAX],f[MAX][MAXN];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
void pack01()
{
	for(int i=0;i<=n;i++)
	{
		f[i][0]=0;
		f[0][i]=0;
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=MAXN;j++)
		{
			if(j-m[i]-f[i-1][j]>=0&&(m[i]<=A||m[i]<=C)) f[i][j]=max(f[i-1][j],f[i-1][j-m[i]]+m[i]);
			else f[i][j]=f[i-1][j];
		}
}
int main()
{
	while(cin>>A>>C)
	{
		memset(m,0,sizeof(m));
		int sum=0,mm=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i];
			sum+=m[i];
			if(m[i]>mm) mm=m[i];
		}
		pack01();
		if(f[n][A+C]>=sum) cout<<"Yes"<<endl;
		else if((f[n][A+C]+mm)>=sum) cout<<"Need a helper"<<endl;
		else cout<<"No"<<endl;
	}
}*/
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define swap(a,b) {int c=a;a=b;b=c;}
int f[1001];
int max(int a,int b)
{
    return (a>b?a:b);
}
int main()
{
    int i,j,k,m,n,x,v[1001],big=1,total,tmp;
    while (scanf("%d %d",&m,&n)!=EOF)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&x);
        total=0;
        for (i=1;i<=x;i++)
            {scanf("%d",&v[i]);
                if (v[i]>v[big]) big=i;
            total+=v[i];}
        swap(v[big],v[x]);
        for (i=1;i<=x;i++)
            for (j=m;j>=v[i];j--)
            {
                tmp=f[m];
                f[j]=max(f[j-v[i]]+v[i],f[j]);
            }
        if ((total-f[m])<=n) printf("Yes\n");
        else if ((total-v[x]-tmp)<=n) printf("Need a helper\n");
        else printf("No\n");
    }
    return 0;
}
