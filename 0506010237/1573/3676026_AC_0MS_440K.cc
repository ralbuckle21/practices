#include<iostream>
using namespace std;
int n,m,k,c=0;
struct{
    int step;
    int x;
    int y;
    bool visit;   
}r[1000][1000];
char s[1001];
void find(int x,int y){
     if(x<0 || y<0 || x>=n || y>=m){
          printf("%d step(s) to exit\n",c);
          return;       
     }
     if(r[x][y].visit){
          printf("%d step(s) before a loop of %d step(s)\n",r[x][y].step-1,c-r[x][y].step+1);
          return;                  
     }
     r[x][y].visit = true; 
     r[x][y].step = ++c;
     find(r[x][y].x,r[x][y].y);
}
int main()
{
     while(true){
         scanf("%d%d%d",&n,&m,&k); 
         if(n==0 && m==0 && k==0) break;
         for(int i=0;i<n;i++){
               scanf("%s",s);
               for(int j=0;j<m;j++){
                    r[i][j].visit=false;
                    switch(s[j]){
                          case 'N': r[i][j].x = i-1; r[i][j].y = j; break;
                          case 'S': r[i][j].x = i+1; r[i][j].y = j; break;
                          case 'E': r[i][j].x = i; r[i][j].y = j+1; break;
                          case 'W': r[i][j].x = i; r[i][j].y = j-1; break;             
                    }        
               }  
         } 
         find(0,k-1);
         c=0;          
     }
     system("pause");
     return 0;
}
