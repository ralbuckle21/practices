/*#include<cstdio>
int calc(int n)
{
	int ret=0;
	while(n>0){
		ret+=n%10;
		n/=10;
	}
	if(ret>=10) calc(ret);
	else return ret;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n!=0){
		printf("%d\n",calc(n));
	}
}*/
#include <iostream>
using namespace std;
int main()
{
    char n[10100];
    while(cin>>n&&n[0]!='0'){
        int t=0;
        for(int i=0;n[i]!='\0';i++){
            t+=(n[i]-'0');
            if(t>=10) t=t%10+t/10;
        }
        cout<<t<<endl;
    }
}