#include <iostream>
using namespace std;
char f[202][202];
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)&&n)
	{
		int c=0;
		memset(f,0,sizeof(m));
		getchar();
		for(int i=1;i<=n;i++){
			scanf("%s",&f[i]);
			for(int j=0;j<m;j++){
				if(f[i][j]=='S') c++;
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(f[i][j]=='S')
					if((f[i+1][j]=='S'&&f[i][j+1]=='S')||(f[i+1][j]=='S'&&f[i][j-1]=='S')) c--;
			}
		printf("%d\n",c);
	}
}