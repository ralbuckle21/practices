#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	int resc=0,resp=0;
	char resn[100];
	scanf("%d",&n);
	while(n--){
		char name[100];
		int q[4],t[4],cnt=0,pen=0;
		scanf("%s %d %d %d %d %d %d %d %d",&name,&q[0],&t[0],&q[1],&t[1],&q[2],&t[2],&q[3],&t[3]);
		for(int i=0;i<4;i++){
			if(t[i]>0){
				cnt++;
				pen+=((q[i]-1)*20+t[i]);
			}
		}
		if(cnt>resc){
			strcpy(resn,name);
			resc=cnt;
			resp=pen;
		}
		if(cnt==resc&&pen<resp){
				strcpy(resn,name);
				resp=pen;
		}
	}
	printf("%s %d %d\n",resn,resc,resp);
}