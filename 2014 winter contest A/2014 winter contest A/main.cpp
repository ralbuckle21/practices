#include<iostream>
#include<algorithm>
using namespace std;
int dp[42][42][42][42],table[355],cur=0;
int n,m,a1=0,a2=0,a3=0,a4=0;
int max(int a,int b,int c,int d){
	int temp[4]={a,b,c,d},res=0;
	sort(temp,temp+4);
	return temp[3];
}
int cal(int i,int j,int k,int l,int mk){
	int pos;
	if(i>a1||j>a2||k>a3||l>a4) 
		return 0;
	pos=(a1-i)+2*(a2-j)+3*(a3-k)+4*(a4-l)+mk;
	return table[pos];
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&table[i]);
	}
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		if(t==1) a1++;
		else if(t==2) a2++;
		else if(t==3) a3++;
		else a4++;
	}
	memset(dp,0,sizeof(dp));
	dp[a1][a2][a3][a4]=0;
	for(int i=a1;i>=0;i--){
		for(int j=a2;j>=0;j--){
			for(int k=a3;k>=0;k--){
				for(int l=a4;l>=0;l--){
					dp[i][j][k][l]=max(cal(i+1,j,k,l,1)+dp[i+1][j][k][l],cal(i,j+1,k,l,2)+dp[i][j+1][k][l],cal(i,j,k+1,l,3)+dp[i][j][k+1][l],cal(i,j,k,l+1,4)+dp[i][j][k][l+1]);
				}
			}
		}
	}
	printf("%d\n",dp[0][0][0][0]+table[0]);
}