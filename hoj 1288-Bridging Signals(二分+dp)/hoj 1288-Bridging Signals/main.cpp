#include <stdio.h>
#include<iostream>
#define maxn 40005
int cas,n,k,a[maxn],len;
void cal(){
	if(k<a[len]){
		int l=1,r=len,m;
		while(l<r){//���ַ�ö�ٲ���λ��
			m=(l+r)/2;
			if(a[m]>=k)
				r=m;
			else l=m+1;//ע������Ҫ+1
		}
		a[l]=k;
	}
	else{//���Խ��е�������
		a[++len]=k;
	}
}
int main()
{
	scanf("%d",&cas);
	while(cas--){
		int res;
		len=0;
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&k);
			cal();
		}
		/*for(int i=0;i<n;i++){
			printf("%d ",a[i]);
		}*/
		printf("%d\n",len);
	}
}