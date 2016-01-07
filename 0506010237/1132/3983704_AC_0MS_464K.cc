#include<iostream>
using namespace std;
char c[33][33];
int t,x,y,cs=1;
void init(){
    for(int i=0;i<32;i++)
        for(int j=0;j<32;j++)
            c[i][j]='.'; 
}
void output(){
    cout<<"Bitmap #"<<cs++<<endl;
    for(int i=31;i>=0;i--) cout<<c[i]<<endl;     
    cout<<endl;
}
int main(){
    char mg[1000];
    scanf("%d",&t);
    while(t--){
         init();
         scanf("%d%d%s",&y,&x,mg); 
         int len=strlen(mg)-1;
         for(int i=0;i<len;i++)
             switch(mg[i]){
                  case 'E': c[x-1][y]='X'; y=y+1; break;
                  case 'N': c[x][y]='X'; x=x+1; break;
                  case 'W': y=y-1; c[x][y]='X'; break;            
                  case 'S': x=x-1; c[x][y-1]='X'; break;          
             }
         output();          
    }
    system("pause");
    return 0;
}
