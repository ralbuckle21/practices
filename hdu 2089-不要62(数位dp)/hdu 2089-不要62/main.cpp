#include<cstdio>
#include<string>
#define MAXN 1000010
bool d[MAXN];
void cal()
{
	char temp[10];
	for(int i=0;i<MAXN;i++)
	{
		if(strstr(itoa(i,temp,10),"62")!=NULL||strstr(itoa(i,temp,10),"4")!=NULL)
		    d[i]=false;
		else d[i]=true;
	}
}
int main()
{
	cal();
	int t1,t2;
	while(scanf("%d %d",&t1,&t2))
	{
		if(t1==0&&t2==0)
			break;
		int ans=0;
		for(int i=t1;i<=t2;i++)
			if(d[i])
				ans++;
		printf("%d\n",ans);
	}
}