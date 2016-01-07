#include<iostream>
using namespace std;
int n,m;
bool flag;
int f[30];
int degree[30],degree1[30];
int num[30][30];
void init(){
    for(int i=1;i<=n;i++) f[i]=i;
    memset(num,0,sizeof(num));
    memset(degree,0,sizeof(degree));    
    flag=false;
}
void cy(){
    for(int i=1;i<=n;i++) degree1[i]=degree[i];     
}
int find(int x){
    int r=x;
    while(r!=f[r]) r=f[r]; 
    while(x!=r){ 
         int temp=f[x];
         f[x]=r;
         x=temp;            
    }   
    return r;
}
void unions(int x,int y){
    x=find(x),y=find(y);
    if(x>y) f[y]=x;
    else if(x<y) f[x]=y;    
}
bool topsort(){
	int i,count=0;
	while(true){
		i=1;
		while(i<=n && degree1[i]!=0) i++;
		if(i>n) break;
		count++;
		degree1[i]=-1; 
		for(int j=1;j<=num[i][0];j++) degree1[num[i][j]]--;
	}
	if(count<n) return false;
	return true;
}
void solve(){
    char mg[3];
    int a,b,i,j; 
    init();
    for(i=1;i<=m;i++){
         scanf("%s",mg);
         if(!flag){
              a=mg[0]-'A'+1; b=mg[2]-'A'+1;
              num[a][++num[a][0]]=b;
              degree[b]++;
              cy();
              if(!topsort()){ flag=true; j=i; }
         }   
         if(!flag) unions(a,b);     
    }     
    if(flag) printf("Inconsistency found after %d relations.\n",j);
    else{
          a=find(1);
          for(i=2;i<=n;i++) if(find(i)!=a) break;
          if(i<=n) printf("Sorted sequence cannot be determined.\n");
          else{ 
             printf("Sorted sequence determined after %d relations: ",n);
             for(int i=1;i<=n;i++) printf("%c",'A'+i-1);
             printf(".\n");
          }    
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF && n!=0) solve();
    system("pause");
    return 0;
}
