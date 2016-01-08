#include<iostream>
#include<cstring>
using namespace std;
int fib[32]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578};
int ori(char *s)
{
	int ret=0;
	for(int i=strlen(s)-1;i>=0;i--){
		ret+=(s[i]-'0')*fib[strlen(s)-i-1];
	}
	return ret;
}
void std_form(char *s,int o)
{
	char *ret=new char[33];
	int i=31,j=0;
	while(o<fib[i]) i--;
	for(i,j;i>=0;i--,j++)
	{
		if(o>=fib[i]){
			ret[j]='1';
			o-=fib[i];
		}
		else ret[j]='0';
	}
	printf("%s\n",ret);
}
int main()
{
	char *s=new char[33];
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",&s);
		int o=ori(s);
		printf("%d in decimal, \n",o);
		std_form(s,o);
	}
}