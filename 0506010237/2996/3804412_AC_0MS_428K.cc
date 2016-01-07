#include<iostream>
using namespace std;
int chess[32][2]={0};
int sign[256];
char ch[40]={"KQRRBBNNPPPPPPPPKQRRBBNNPPPPPPPP"};
void init(){
    sign['K']=0;sign['Q']=1;sign['R']=2;sign['B']=4;sign['N']=6;sign['P']=8;
    sign['k']=16;sign['q']=17;sign['r']=18;sign['b']=20;sign['n']=22;sign['p']=24;
}
char c[20][40];
int main()
{
     init();
     int x=1,y;
     for(int i=0;i<17;i++) scanf("%s",c[i]);
     for(int i=15;i>7;i=i-2){
          y=0;
          for(int j=2;j<=32;j+=4){
               y++;
               if(c[i][j]==':' || c[i][j]=='.') continue;
               int k=sign[c[i][j]]; 
               while(chess[k][0]!=0) k++;
               chess[k][0]=x; chess[k][1]=y;        
          }
          x++;   
     }
     x=8;
     for(int i=1;i<8;i=i+2){
          y=0;
          for(int j=2;j<=32;j+=4){
               y++;
               if(c[i][j]==':' || c[i][j]=='.') continue;
               int k=sign[c[i][j]]; 
               while(chess[k][0]!=0) k++;
               chess[k][0]=x; chess[k][1]=y;        
          }
          x--;   
     }
     printf("White: ");
     bool st=false;
     for(int i=0;i<8;i++){
         if(chess[i][0]!=0){
              if(st) printf(",");
              printf("%c%c%d",ch[i],chess[i][1]+'a'-1,chess[i][0]);  st=true; 
         }
     }
     for(int i=8;i<16;i++){
         if(chess[i][0]!=0){ 
              if(st) printf(",");
              printf("%c%d",chess[i][1]+'a'-1,chess[i][0]); st=true; 
         }     
     }
     printf("\n"); printf("Black: ");
     st=false;
     for(int i=16;i<24;i++){
        if(chess[i][0]!=0){ 
                if(st) printf(",");
                printf("%c%c%d",ch[i],chess[i][1]+'a'-1,chess[i][0]); st=true; 
        }
     }
     for(int i=24;i<32;i++){
        if(chess[i][0]!=0){ 
                if(st) printf(",");
                printf("%c%d",chess[i][1]+'a'-1,chess[i][0]); st=true; 
        }     
     }
     printf("\n");
     system("pause");
     return 0;
}
