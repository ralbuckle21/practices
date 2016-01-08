#ifdef unix
  #define LLD "%lld"
#else
  #define LLD "%I64d"
#endif
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
int int f[12][10],d[12];//d[x]=sigma(j=1..9)f[x][j]为有x位的w数的个数。
//f[i][j]为有i位，且第i位(从右数,下同)为j的w数的个数
int b[13];//把n按照需要的进制拆分为b[],从左到右逐位扫描，扫到某一位b[i]时，假定该位不足b[i]，统计方案数；
//然后把该位固定为b[i]，以此为前提条件继续考虑下一位
  int int calc(int int n){
    if(n<10)return n-1;
    int i,j,len=0;
    int int ans=0;
    while(n){b[++len]=n%10;n/=10;}//分别为b插入区间左右值的各位数
    for(i=1;i<len;++i)ans+=d[i];//先把有效的d全加上，不包括i位
    for(i=len;i;--i){
      if(i==len){//最高位的处理方式
        for(j=1;j<b[i];++j)ans+=f[i][j];//考虑最高位时下界条件j=1而不是j=0，把最高位<n最高位的都加上
      }
	  else{//对于每个位b[i]，分别假定j=0..b[i]-1，ans+=f[i][j]
        if(b[i])
          for(j=0;j<b[i];++j)
            if(abs(j-b[i+1])>1)// 如果abs(j-b[i+1])<=1，对应的方案数不应被累加
              ans+=f[i][j];
      }
      if(i!=len&&abs(b[i]-b[i+1])<=1)break;//检查b[i]和b[i+1]，看他们是否满足w数的条件
    }
    return ans;
}
int main(){
  int int L,R;
  int i,j,k;
  scanf(LLD LLD,&L,&R);
  for(i=0;i<10;++i) f[1][i]=1;//个位数，初始化为1
  for(i=2;i<=10;++i)
    for(j=0;j<10;++j)//新数，即f[i]的最后一位
      for(k=0;k<10;++k)//旧数，即f[i-1]的最后一位
        if(abs(j-k)>1)
          f[i][j]+=f[i-1][k];//f统计w数的数量，在这里进行判定
  for(i=1;i<=10;++i)
    for(j=1;j<10;++j)
      d[i]+=f[i][j];//初始化d,d是i位数中w数的个数
  printf(LLD "\n",calc(R+1)-calc(L));
  return 0;
}
/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10+5;
int dp[MAX][13][3],digit[MAX];
/*
size表示输入的数的长度,则: 
dp[i][j][0]表示从size到i+1位不含有13且接下去长度<=i的模13为j的数的个数
dp[i][j][1]表示从size到i+1位不含有13但是第i+1位是1且接下去长度<=i的模13为j的数的个数
dp[i][j][2]表示从size到i+1位含有13且接下去长度<=i的模13为j的数的个数 
*/

void init(int n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
	memset(dp,-1,sizeof dp);
}

//size代表后面几位数,mod代表当前总的余数,mark表示3种情况,flag标记的作用 
int digit_dfs(int size,int mod,int mark,bool flag){//记忆化搜索 
	if(!size)return !mod && mark == 2;//表示所有数搜完
	if(flag && dp[size][mod][mark] != -1)return dp[size][mod][mark];//表示后面长度可以任意数且已经搜索过
	int m=flag?9:digit[size];//判断当前这个数的范围
	int sum=0;
	for(int i=0;i<=m;++i){
		int Mod=(mod*10+i)%13;
		int Mark=mark;
		if(mark != 2 && i != 1)Mark=0;//第一种情况 
		if(mark != 2 && i == 1)Mark=1;//第二种情况 
		if(mark == 1 && i == 3)Mark=2;//第三种情况 
		sum+=digit_dfs(size-1,Mod,Mark,flag || i<m); 
	} 
	if(flag)dp[size][mod][mark]=sum;//记忆好,下次不用再搜索
	return sum; 
}

int main(){
	int n;
	while(cin>>n){
		init(n);
		cout<<digit_dfs(digit[0],0,0,0)<<endl;
	}
	return 0;
}
*/