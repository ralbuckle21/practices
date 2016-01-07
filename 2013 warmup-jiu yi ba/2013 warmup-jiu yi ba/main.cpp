#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define inf 99999999;
int input[10005],output[10005];
int main(){
	char * day[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
	int n,count=0;
	while(scanf("%d",&n)!=EOF&&n!=0){
		input[count]=n;
		count++;
	}
	sort(input,input+count);
	for(int i=0;i<count;i++){
		int t;
		t=365*(input[i]-1000);
		int temp=(input[i]-1000)/4;
		t+=temp;
		output[i]=(t+1)%7;
	}
	for(int i=0;i<count;i++){
		int temp=(output[i]+2)%7;
		printf("%d-09-18 %s\n",input[i],day[temp]);
	}
	printf("Never forget 9-18, folks.\n");
}