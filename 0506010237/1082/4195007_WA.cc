#include<iostream>
using namespace std;
bool day[2003][13][32];
bool flag[2003][13][32];
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t;
bool neap(int k){
     if(k%4==0 && k%100!=0) return true;
     return false;
}
bool win(int x,int y,int z){
     bool ok=true;
     int sx=x,sy=y+1,sz=z,dx=x,dy=y,dz=z+1;
     if(x>2001 || (x==2001 && (y>11 || (y==11 && z>4)))) return true;
     if(flag[x][y][z]) return day[x][y][z];
     flag[x][y][z]=true;
     if(y==1){
          if(neap(x)){
               if(z>29) ok=false;
          }
          else if(z>28) ok=false;            
     }
     else if(z==31 && y!=7) ok=false;
     if(sy==12){ sx=sx+1; sy=1;}
     if( !(neap(x) && y==2) && month[dy]<dz){ 
                dy++; dz=1;
                if(dy>12){ dx=dx+1; dy=1;}     
     } 
     if(ok){
          if(!win(sx,sy,sz) || !win(dx,dy,dz)) day[x][y][z]=true;      
     } 
     else if(!win(dx,dy,dz)) day[x][y][z]=true;
     return day[x][y][z];   
}
int main(){
    int x,y,z;
    scanf("%d",&t);
    while(t--){
         scanf("%d%d%d",&x,&y,&z);
         if(win(x,y,z)) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;           
    }
    system("pause");
    return 0;
}
