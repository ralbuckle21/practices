#include<iostream>
using namespace std;
struct{
    int x;
	int y;
	int xy;
	int v;
}num[5][5];
int n;
void find(int a,int b){
	if(a==0 && b!=4){
        for(int k=1;k<=9;k++){
            if(num[a][b-1].x+k<n){
                num[a][b].x=num[a][b-1].x+k;
				num[a][b].y=k;
				num[a][b].v=k;
				find(a,b+1);
				num[a][b].x-=k;
			}
		}
	}
	else if(b==0 && a!=4){
         for(int k=1;k<=9;k++){
            if(num[a-1][b].y+k<n){
                num[a][b].y=num[a-1][b].y+k;
				num[a][b].x=k;
				num[a][b].v=k;
				find(a,b+1);
				num[a][b].y-=k;
			}
		} 
	}
	else if(a==4 && b!=4){
		if(b==0){
            for(int k=1;k<=9;k=k+2){
                if(num[a-1][b].y+k==n && num[a-1][b].xy+k==n){
                     num[a][b].y=num[a-1][b].y+k;
					 num[a][b].x=k;
					 num[a][b].v=k;
					 find(a,b+1);
					 num[a][b].y-=k;
				}
            }
		}
		else{
            for(int k=1;k<=9;k=k+2){
				if(num[a-1][b].y+k==n && num[a][b-1].x+k<n){
                     num[a][b].y=num[a-1][b].y+k;
                     num[a][b].x=num[a][b-1].x+k;
					 num[a][b].v=k;
					 find(a,b+1);
					 num[a][b].y-=k;
					 num[a][b].x-=k;
				}
			}
		}
	}
	else if(b==4 && a!=4){
        if(a==0){
            for(int k=1;k<=9;k=k+2){
                if(num[a][b-1].x+k==n){
                     num[a][b].x=num[a][b-1].x+k;
					 num[a][b].y=k;
					 num[a][b].v=k;
					 find(a+1,0);
					 num[a][b].x-=k;
				}
            }
		}
		else{
            for(int k=1;k<=9;k=k+2){
				if(num[a][b-1].x+k==n && num[a][b-1].y+k<n){
                     num[a][b].y=num[a-1][b].y+k;
                     num[a][b].x=num[a][b-1].x+k;
					 num[a][b].v=k;
					 find(a+1,0);
					 num[a][b].y-=k;
					 num[a][b].x-=k;
				}
			}
		}   

	}
	else if(a==4 && b==4){
		for(int k=1;k<=9;k=k+2){
            if(num[a-1][b].y+k==n && num[a][b-1].x+k==n && num[a-1][b-1].xy+k==n){
                  num[a][b].v=k;
				  for(int i=0;i<5;i++){
					  for(int j=0;j<5;j++) printf("%d",num[i][j].v);
					  printf("\n");
				  }
				  printf("\n");
			}
		}
	}
    else{
        for(int k=0;k<=9;k++){
			if(a==b){
                if(num[a-1][b].y+k<n && num[a][b-1].x+k<n && num[a-1][b-1].xy+k<n && num[a-1][b+1].xy+k<n){
                     num[a][b].y=num[a-1][b].y+k;
                     num[a][b].x=num[a][b-1].x+k;
					 num[a][b].xy=num[a-1][b-1].xy+k;
					 num[a][b].v=k;
					 find(a,b+1);
					 num[a][b].y-=k;
					 num[a][b].x-=k;
					 num[a][b].xy-=k;
				}
			}
            else{
                if(num[a-1][b].y+k<n && num[a][b-1].x+k<n){
                     num[a][b].y=num[a-1][b].y+k;
                     num[a][b].x=num[a][b-1].x+k;
					 num[a][b].v=k;
					 find(a,b+1);
					 num[a][b].y-=k;
					 num[a][b].x-=k;
				} 
 
			}
		}
	}
}
int main(){
    int a;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			num[i][j].x=num[i][j].y=num[i][j].xy=0;
	scanf("%d %d",&n,&a);
	num[0][0].x=num[0][0].y=num[0][0].xy=num[0][0].v=a;
	find(0,1);
    system("pause");
	return 0;
}