#include<iostream>
#include<queue>
using namespace std;
int mov[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int maze[32][32][32];
struct point{
	int x,y,z,s;
};
int main()
{
	int k,r,c;
	while(scanf("%d %d %d",&k,&r,&c)&&k){
		char temp;
		point start,end;
		for(int i=0;i<k;i++)
			for(int j=0;j<r;j++)
				for(int l=0;l<c;l++){
					cin>>temp;
					if(temp=='S'){
						start.x=i;
						start.y=j;
						start.z=l;
						start.s=0;
						maze[i][j][l]=1;
					}
					else if(temp=='E'){
						end.x=i;
						end.y=j;
						end.z=l;
						end.s=0;
						maze[i][j][l]=1;
					}
					else if(temp=='.')
						maze[i][j][l]=1;
					else
						maze[i][j][l]=0;
				}
		queue<point> steps;
		while(!steps.empty())
			steps.pop;
		bool visited[32][32][32]={false};
		steps.push(start);
		point t;
		while(!steps.empty){
			t=steps.front();
			steps.pop();
			if(t.x==end.x&&t.y==end.y&&t.z==end.z){
				printf("%d",end.s);
				break;
			}
			else{

			}
		}
	}
}