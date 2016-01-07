#include <iostream>
using namespace std;
bool flag[1001][1001];
int n;
struct point{
	int x,y;
}p[1001];
int main(){
	int s=0;
	while(scanf("%d",&n)!=EOF){
	     memset(flag,0,sizeof(flag));
		 for(int i=1;i<=n;i++) scanf("%d%d",&p[i].x,&p[i].y);
		 for(int i=1;i<=n;i++){
		      for(int j=i+1;j<=n;j++){
			       if(!flag[i][j]){
						 int ans=0;
						 for(int x=j+1;x<=n;x++){
						      if(!flag[j][x]){
							       if((p[x].y-p[i].y)*(p[j].x-p[i].x)-(p[j].y-p[i].y)*(p[x].x-p[i].x)==0){
								           ans++;
										   flag[j][x]=true;		
								   }		
							  }		
						 }
						 if(ans>s) s=ans;
					}		
			  }		
		 }
		 printf("%d\n",s+2);	
	}
   system("pause");
}
