#include<iostream>
using namespace std;
int t,n,m;
bool a[1001][1001];
void init(){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           a[i][j]=false;     
}
void change(int x1,int y1,int x2,int y2){
     for(int i=x1;i<=x2;i++)
         for(int j=y1;j<=y2;j++)
              a[i][j]=a[i][j]^1;        
}
int main()
{
    char c;
    int x,x2,y,y2;
    scanf("%d",&t);
    while(t--){
         scanf("%d %d",&n,&m);
         init();
         while(m--){
             scanf("%c",&c);
             while(c=='\n') scanf("%c",&c);
             if(c=='C'){
                  scanf("%d %d %d %d",&x,&y,&x2,&y2);
                  change(x,y,x2,y2);      
             }
             else{
                  scanf("%d %d",&x,&y);
                  printf("%d\n",a[x][y]);
             }       
         }        
    }
    system("pause");
    return 0;
}
