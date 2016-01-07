#include<iostream>
using namespace std;
bool rect[30][10];
const int r=0,c=9,s=18;
int num[10][10];
int t;
bool sign;
int sub(int x,int y){
     if(x<=3 && y<=3) return 19;
     else if(x<=3 && y<=6) return 20;
     else if(x<=3 && y<=9) return 21;
     else if(x<=6 && y<=3) return 22;
     else if(x<=6 && y<=6) return 23;
     else if(x<=6 && y<=9) return 24;
     else if(x<=9 && y<=3) return 25;
     else if(x<=9 && y<=6) return 26;
     else return 27;    
}
void readdata(){
     char mg[12];
     for(int i=1;i<=9;i++){
          scanf("%s",mg+1);
          for(int j=1;j<=9;j++){
                num[i][j]=mg[j]-'0';
                rect[r+i][num[i][j]]=true;
                rect[c+j][num[i][j]]=true;
                int h=sub(i,j);
                rect[h][num[i][j]]=true;        
          }             
     }    
}
void output(){
     for(int i=1;i<=9;i++){
         for(int j=1;j<=9;j++)
             printf("%d",num[i][j]);
         printf("\n");
     } 
}
void deal(int x,int y){
     if(sign) return;
     if(x==0){
          output();
          sign=true;    
          return;  
     }
     if(num[x][y]!=0){
         if(y>1) deal(x,y-1);
         else deal(x-1,9);                 
     }
     else{
        int h=sub(x,y);
        for(int i=1;i<=9;i++){
           if(!rect[r+x][i] && !rect[c+y][i] && !rect[h][i]){
                num[x][y]=i; rect[r+x][i]=true; rect[c+y][i]=true; rect[h][i]=true;
                if(y>1) deal(x,y-1);
                else deal(x-1,9); 
                num[x][y]=0; rect[r+x][i]=false; rect[c+y][i]=false; rect[h][i]=false;                 
           }        
        }
     }     
}
int main()
{
     scanf("%d",&t);
     while(t--){
           memset(rect,0,sizeof(rect));
           sign=false;
           readdata();         
           deal(9,9);     
     }
     system("pause");
     return 0;
}
