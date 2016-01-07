#include<iostream>
using namespace std;
bool flag[3125][9][366]; /*前5(5^5)天云的移动状态,云当今的位置 ,第几天*/
/*数组判重,每次只需保存前6次=前5次+云的位置以及天数*/  
int s[366]; //节日2进制数字化 
int n;
bool check(int k,int x,int y,long long &state,int last){
     long long newstate=0;
     if(x<0 || y<0 || x>2 || y>2) return false;
     if(flag[last][x*3+y][k]) return false; 
     flag[last][x*3+y][k]=true;
     int c=(3<<(14-(4*x+y)))|(3<<(10-(4*x+y)));
     if(c&s[k]) return false; //节日地点下了雨 
     for(int i=0;i<16;i++){
          long long tmp=(state>>((15-i)*3))&7; //此地过去7天的下雨状况 
          tmp=((c>>(15-i)&1)?(-1):tmp);
          tmp++;
          if(tmp>=7) return false; //连续7天未下雨 
          newstate |= (tmp<<((15-i)*3)); //各地的下雨状况       
     } 
     state=newstate;
     return true;
}
bool dfs(int k,int x,int y,long long state,int last){
    int sx,sy;
    if(k>=n) return true;
    if(!check(k,x,y,state,last)) return false;
    for(int i=0;i<=4;i++){
         sx=x,sy=y;
         if(i==1) sx=(x+1)%3;
         else if(i==2) sx=(x+2)%3;
         else if(i==3) sy=(y+1)%3;
         else if(i==4) sy=(y+2)%3;
         if(dfs(k+1,sx,sy,state,last/5+625*i)) return true;        
    }     
    return false;
}
int main(){
    int tmp;
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++)
           for(int j=0;j<16;j++){
               cin>>tmp;         
               s[i]=((s[i]<<1)|tmp);
           }  
        if(dfs(0,1,1,0,0)) cout<<1<<endl;
        else cout<<0<<endl;
    }
    system("pause");
    return 0;
}
