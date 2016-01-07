#include<iostream>
using namespace std;
struct{
    int v;
    bool x,y,xy,yx;       
}num[19][19];
int t;
int findyx(int i,int j,int k){
    if(j<0 || i>18) return 0; 
    if(num[i][j].v!=k) return 0;
    num[i][j].yx=true;
    return 1+findyx(i+1,j-1,k); 
}
int findxy(int i,int j,int k){
    if(i>18 || j>18) return 0;
    if(num[i][j].v!=k) return 0;
    num[i][j].xy=true;
    return 1+findxy(i+1,j+1,k); 
}
int findx(int i,int j,int k){
    if(j>18) return 0;
    if(num[i][j].v!=k) return 0;
    num[i][j].x=true;
    return 1+findyx(i,j+1,k); 
}
int findy(int i,int j,int k){
    if(i>18) return 0;
    if(num[i][j].v!=k) return 0;
    num[i][j].y=true;
    return 1+findyx(i+1,j,k); 
}
void find(){
    for(int i=0;i<19;i++)
       for(int j=0;j<19;j++){
             if(i<=14 && j>=4){
                  if(num[i][j].v==1 && !num[i][j].yx && findyx(i,j,1)==5){ cout<<1<<endl<<i+5<<" "<<j-3<<endl; return;} 
                  if(num[i][j].v==2 && !num[i][j].yx && findyx(i,j,2)==5){ cout<<2<<endl<<i+5<<" "<<j-3<<endl; return;}   
             }
             if(i<=14 && j<=14){
                  if(num[i][j].v==1 && !num[i][j].xy && findxy(i,j,1)==5){ cout<<1<<endl<<i+1<<" "<<j+1<<endl; return;} 
                  if(num[i][j].v==2 && !num[i][j].xy && findxy(i,j,2)==5){ cout<<2<<endl<<i+1<<" "<<j+1<<endl; return;}                       
             }
             if(j<15){
                  if(num[i][j].v==1 && !num[i][j].x && findx(i,j,1)==5){ cout<<1<<endl<<i+1<<" "<<j+1<<endl; return;} 
                  if(num[i][j].v==2 && !num[i][j].x && findx(i,j,2)==5){ cout<<1<<endl<<i+1<<" "<<j+1<<endl; return;} 
             }
             if(i<15){
                  if(num[i][j].v==1 && !num[i][j].y && findy(i,j,1)==5){ cout<<1<<endl<<i+1<<" "<<j+1<<endl; return;} 
                  if(num[i][j].v==2 && !num[i][j].y && findy(i,j,2)==5){ cout<<1<<endl<<i+1<<" "<<j+1<<endl; return;} 
             }      
       }  
       cout<<0<<endl;   
}
int main()
{
    scanf("%d",&t);
    while(t--){
       memset(num,0,sizeof(num));
        for(int i=0;i<19;i++)
            for(int j=0;j<19;j++)
               scanf("%d",&num[i][j].v);    
       find();       
    }
    system("pause");
    return 0;
}
