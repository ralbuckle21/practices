#include<iostream>
using namespace std;
char res[102][102],tmp[102][102];
bool cmp(char a,char b)
{
	if(a=='R'&&b=='S') return true;
	if(a=='S'&&b=='P') return true;
	if(a=='P'&&b=='R') return true;
	return false;
}
char trans(char a)
{
	if(a=='R') return 'P';
	if(a=='S') return 'R';
	if(a=='P') return 'S';
}
int main()
{
	int cas,sb;
	scanf("%d",&cas);
	sb=cas;
	while(cas--){
		int n,m,t;
		memset(tmp,0,sizeof(tmp));
		memset(res,0,sizeof(res));
		scanf("%d %d %d",&n,&m,&t);
		getchar();
		for(int i=0;i<n;i++)
			scanf("%s",tmp[i]);
		if(cas!=(sb-1)) printf("\n",t,cas);
		while(t--){
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++){
					if(i==0&&j==0){
						if(cmp(tmp[1][0],tmp[0][0])||cmp(tmp[0][1],tmp[0][0])) res[0][0]=trans(tmp[0][0]);
						else res[0][0]=tmp[0][0];
					}
					else if(i==0){
						if(cmp(tmp[0][j+1],tmp[0][j])||cmp(tmp[0][j-1],tmp[0][j])||cmp(tmp[1][j],tmp[0][j])) res[0][j]=trans(tmp[0][j]);
						else res[0][j]=tmp[0][j];
					}
					else if(j==0){
						if(cmp(tmp[i-1][0],tmp[i][0])||cmp(tmp[i+1][0],tmp[i][0])||cmp(tmp[i][1],tmp[i][0])) res[i][0]=trans(tmp[i][0]);
						else res[i][0]=tmp[i][0];
					}
					else{
						if(cmp(tmp[i-1][j],tmp[i][j])||cmp(tmp[i+1][j],tmp[i][j])||cmp(tmp[i][j-1],tmp[i][j])||cmp(tmp[i][j+1],tmp[i][j])) res[i][j]=trans(tmp[i][j]);
						else res[i][j]=tmp[i][j];
					}
				}
			memcpy(tmp,res,sizeof(res));
		}
		for(int i=0;i<n;i++){
				res[i][m]='\0';
				printf("%s\n",res[i]);
		}
	}
}
/*#include <cstdio>
#include <algorithm>
using namespace std;

const char *KIND = "RSP";
const int MAX = 128;
const int DIR[][2] = { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };

inline int code(char);

int main()
{
	char kingdom[MAX][MAX];
	int t, T, i, j, k, d;
	int h, w, day;
	
	scanf("%d", &T);
	for(t = 0; t < T; t++) {
		scanf("%d %d %d\n", &h, &w, &day);
		for(i = 0; i < h; i++) gets(kingdom[i]);
		bool change = true;
		for(d = 0; d < day && change; d++) {
			char next[MAX][MAX]; change = false;
			memcpy(next, kingdom, sizeof(kingdom));
			for(i = 0; i < h; i++)
				for(j = 0; j < w; j++)
					for(k = 0; k < 4; k++) {
						int x = i+DIR[k][0], y = j+DIR[k][1];
						if(x < 0 || x >= h || y < 0 || y >= w) continue;
						int oa = code(kingdom[i][j]), ob = code(kingdom[x][y]);
						if(oa == (ob+1)%3) { next[i][j] = kingdom[x][y]; change = true; break; }
					}
			memcpy(kingdom, next, sizeof(next));
		}
		if(t != 0) putchar('\n');
		for(i = 0; i < h; i++) puts(kingdom[i]);
	}
	
	return 0;
}

inline int code(char form)
{
	int o;
	for(o = 0; form != KIND[o]; o++) ;
	return o;
}*/
