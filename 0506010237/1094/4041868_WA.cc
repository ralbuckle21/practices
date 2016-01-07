#include<iostream>
using namespace std;
int n,m;
bool flag,sign;
int degree[30],degree1[30];
int num[30][30];
int result[30],len;
void init(){
    memset(num,0,sizeof(num));
    memset(degree,0,sizeof(degree));    
    flag=false; sign=false;
}
void cy(){
    for(int i=1;i<=n;i++) degree1[i]=degree[i];     
}
int topsort(){
	int x,y,z=0;
	for(int k=1;k<=n;k++){
		x=0;
		for(int i=1;i<=n;i++) 
            if(degree1[i]==0){
                x++;
                y=i;               
            } 
        if(x>1) z=1;
		if(x==0) return -1;
		degree1[y]=-1; result[k]=y;
		for(int j=1;j<=num[y][0];j++) degree1[num[y][j]]--;
	}
	if(z==1) return 0;
	return 1;
}
void solve(){
    char mg[3];
    int a,b,i,j; 
    init();
    for(i=1;i<=m;i++){
         scanf("%s",mg);
         if(!flag && !sign){
              a=mg[0]-'A'+1; b=mg[2]-'A'+1;
              num[a][++num[a][0]]=b;
              degree[b]++;
              cy(); int v=topsort();
              if(v==-1){ flag=true; j=i; }
              else if(v==1){ sign=true; j=i;}                      
         }    
    }     
    if(flag) printf("Inconsistency found after %d relations.\n",j);
    else if(!sign) printf("Sorted sequence cannot be determined.\n");
    else{ 
             printf("Sorted sequence determined after %d relations: ",n);
             for(i=1;i<=n;i++) printf("%c",'A'+result[i]-1);
             printf(".\n");  
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF && n!=0) solve();
    system("pause");
    return 0;
}
