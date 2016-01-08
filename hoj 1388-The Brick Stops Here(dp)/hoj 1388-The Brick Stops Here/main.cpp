/*#include<iostream>
using namespace std;
#define MAX 225
#define MAXN 1086*30
int n,m;
int f[30][MAXN],g,p[MAX],v[MAX],cmax,cmin;
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
void pack01()//¶þÎ¬01±³°ü
{
	memset(f,999999,sizeof(f));
	f[0][0]=0;
	for(int i=0;i<m;i++)
	    for(int j=29;j>0;j--)
			for(int k=MAXN-1;k>=p[i];k--)
	            f[j][k]=min(f[j][k],f[j-1][k-p[i]]+v[i]);
}
int main()
{
    cin>>m;
	for(int i=0;i<m;i++)
		cin>>p[i]>>v[i];
	pack01();
	while(cin>>n)
	{
		while(n--)
		{
			int ans=999999;
			cin>>g>>cmin>>cmax;
			for(int i=g*cmin;i<=g*cmax;i++)
			    ans=min(ans,f[g][i]);
			if(ans==999999) cout<<"impossible"<<endl;
			else cout<<ans<<endl;
		}
	}
}*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int inf=0x3f3f3f3f;
int val[202],w[202],f[20002][25];
int main()
{
    int N,V,M,i,j,v;
    while(scanf("%d",&N)&&N!=0){
        V=0;
        for(i=1;i<=N;i++){
            scanf("%d%d",&w[i],&val[i]);
        }
        memset(f,inf,sizeof(f));
        f[0][0]=0;
        V=20002;
        for(j=1;j<=N;j++){
            for(v=V-2;v>=w[j];v--){
                M=min(N,20);
                for(i=1;i<=M;i++)
                     if(f[v-w[j]][i-1]!=inf)
                        f[v][i]=min(f[v][i],f[v-w[j]][i-1]+val[j]);
            }
        }

        int Min,n,Cmin,Cmax;
        cin>>M;
        for(i=1;i<=M;i++){
            scanf("%d%d%d",&n,&Cmin,&Cmax);
            if(n>N){
                printf("impossible\n");
                continue;
            }
            Min=inf;
            for(j=Cmin*n;j<=Cmax*n;j++){
                if(Min>f[j][n])
                    Min=f[j][n];
            }
            if(Min!=inf)printf("%d\n",Min);
            else printf("impossible\n");
        }
    }
    return 0;
}