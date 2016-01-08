#include<cstdio>
using namespace std;
int main()
{
	int n,num[10];
	scanf("%d",&n);
	while(n--){
		for(int i=0;i<10;i++)
			scanf("%d",&num[i]);
		for(int i=0;i<9;i++){
			for(int j=i+1;j<10;j++){
				if(num[i]>num[j]){
					int t=num[i];
					num[i]=num[j];
					num[j]=t;
				}
			}
			printf("%d ",num[i]);
		}
		printf("%d\n",num[9]);
	}
}