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
int int f[12][10],d[12];//d[x]=sigma(j=1..9)f[x][j]Ϊ��xλ��w���ĸ�����
//f[i][j]Ϊ��iλ���ҵ�iλ(������,��ͬ)Ϊj��w���ĸ���
int b[13];//��n������Ҫ�Ľ��Ʋ��Ϊb[],��������λɨ�裬ɨ��ĳһλb[i]ʱ���ٶ���λ����b[i]��ͳ�Ʒ�������
//Ȼ��Ѹ�λ�̶�Ϊb[i]���Դ�Ϊǰ����������������һλ
  int int calc(int int n){
    if(n<10)return n-1;
    int i,j,len=0;
    int int ans=0;
    while(n){b[++len]=n%10;n/=10;}//�ֱ�Ϊb������������ֵ�ĸ�λ��
    for(i=1;i<len;++i)ans+=d[i];//�Ȱ���Ч��dȫ���ϣ�������iλ
    for(i=len;i;--i){
      if(i==len){//���λ�Ĵ���ʽ
        for(j=1;j<b[i];++j)ans+=f[i][j];//�������λʱ�½�����j=1������j=0�������λ<n���λ�Ķ�����
      }
	  else{//����ÿ��λb[i]���ֱ�ٶ�j=0..b[i]-1��ans+=f[i][j]
        if(b[i])
          for(j=0;j<b[i];++j)
            if(abs(j-b[i+1])>1)// ���abs(j-b[i+1])<=1����Ӧ�ķ�������Ӧ���ۼ�
              ans+=f[i][j];
      }
      if(i!=len&&abs(b[i]-b[i+1])<=1)break;//���b[i]��b[i+1]���������Ƿ�����w��������
    }
    return ans;
}
int main(){
  int int L,R;
  int i,j,k;
  scanf(LLD LLD,&L,&R);
  for(i=0;i<10;++i) f[1][i]=1;//��λ������ʼ��Ϊ1
  for(i=2;i<=10;++i)
    for(j=0;j<10;++j)//��������f[i]�����һλ
      for(k=0;k<10;++k)//��������f[i-1]�����һλ
        if(abs(j-k)>1)
          f[i][j]+=f[i-1][k];//fͳ��w��������������������ж�
  for(i=1;i<=10;++i)
    for(j=1;j<10;++j)
      d[i]+=f[i][j];//��ʼ��d,d��iλ����w���ĸ���
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
size��ʾ��������ĳ���,��: 
dp[i][j][0]��ʾ��size��i+1λ������13�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ���
dp[i][j][1]��ʾ��size��i+1λ������13���ǵ�i+1λ��1�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ���
dp[i][j][2]��ʾ��size��i+1λ����13�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ��� 
*/

void init(int n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
	memset(dp,-1,sizeof dp);
}

//size������漸λ��,mod����ǰ�ܵ�����,mark��ʾ3�����,flag��ǵ����� 
int digit_dfs(int size,int mod,int mark,bool flag){//���仯���� 
	if(!size)return !mod && mark == 2;//��ʾ����������
	if(flag && dp[size][mod][mark] != -1)return dp[size][mod][mark];//��ʾ���泤�ȿ������������Ѿ�������
	int m=flag?9:digit[size];//�жϵ�ǰ������ķ�Χ
	int sum=0;
	for(int i=0;i<=m;++i){
		int Mod=(mod*10+i)%13;
		int Mark=mark;
		if(mark != 2 && i != 1)Mark=0;//��һ����� 
		if(mark != 2 && i == 1)Mark=1;//�ڶ������ 
		if(mark == 1 && i == 3)Mark=2;//��������� 
		sum+=digit_dfs(size-1,Mod,Mark,flag || i<m); 
	} 
	if(flag)dp[size][mod][mark]=sum;//�����,�´β���������
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