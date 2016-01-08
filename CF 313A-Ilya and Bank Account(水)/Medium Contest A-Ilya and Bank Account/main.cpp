#include<cstdio>
#include<string.h>
int a[9]={10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int b[9]={1000000000,100000000,10000000,1000000,100000,10000,1000,100,10};
void cal(char *n)
{
	int len=strlen(n),i;
	if(len==3)
    {
		if(n[2]=='0')
		{
           printf("0\n");
		   return;
		}
    }
    if(n[len-1]>n[len-2])
	{
		for(i=0;i<len-1;i++)
			printf("%c",n[i]);
	}
	else
	{
		for(i=0;i<len-2;i++)
	        printf("%c",n[i]);
		printf("%c",n[len-1]);
	}
	printf("\n");
}
int main()
{
	char n[10];
	while(scanf("%s",&n)==1)
	{
		int len=strlen(n),i;
		if(n[0]!='-') printf("%s\n",n);
	    else cal(n);
	}
}
/*#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include<string>
using namespace std;
int main()
{
//freopen("in.txt","r",stdin);
string str;
int i,n;
while(cin>>str)
{
    n=str.length();
    if(str[0]!='-')
    {
        cout<<str<<endl;
    }
    else
    {
        if(n==3)
        {
            if(str[2]=='0')
            {


            cout<<'0'<<endl;
            continue;
            }
        }

        if(str[n-1]>str[n-2])
        {
            for(i=0;i<n-1;i++)
            cout<<str[i];
            cout<<endl;
        }
        else
        {
            for(i=0;i<n-2;i++)
            cout<<str[i];
            cout<<str[n-1]<<endl;;
        }
    }

}

    return 0;
}
*/