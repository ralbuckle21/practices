#include<iostream>
using namespace std;
void search(char *a)
{
	int fc=0,fmc=1;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]=='(')
		{
			int c=0,lc=1,rc=0,ti=i;
			while(lc>=rc&&i<strlen(a))
			{
				i++;
				c++;
				if(a[i]=='(')
					lc++;
				else if(a[i]==')')
					rc++;
			}
			if(i==strlen(a)&&lc>rc)
			{
				i=ti;
				c=-1;
			}
			if(fc<c)
			{
				fc=c;
				fmc=1;
			}
			else if(fc==c)
				fmc++;
		}
	}
	cout<<fc<<' '<<fmc<<endl;
}
int main()
{
	char *a=new char[1000000];
	cin>>a;
	search(a);
}