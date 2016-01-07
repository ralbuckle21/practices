#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
char c[14];
int cmp(const char a,char b)
{
    char c,d;
	c=tolower(a);
	d=tolower(b);
	if(c==d)
		return (a<b);
	return c<d;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",c);
        int len=strlen(c);
        sort(c,c+len,cmp);
      do{
         for(int i=0;i<len;i++)
             printf("%c",c[i]);
         cout<<endl;                                  
      }while(next_permutation(c,c+len,cmp)); 
    }
    system("pause");
    return 0;
}
