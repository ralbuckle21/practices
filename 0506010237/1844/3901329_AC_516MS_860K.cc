#include <iostream>
using namespace std;
const int base=100000;
bool f[2][201000];
int s[500],m;
void init(){
    s[0]=0;
    for(int i=1;i<500;i++) s[i]=s[i-1]+i;
}
void getv(){
    cin>>m;
    int cur=1,pre=0;
     f[cur][base]=true;
     for(int i=1;i<500;i++){
          cur=1-cur; pre=1-pre;
          for(int j=base-s[i-1];j<=base+s[i-1];j++) f[cur][j]=false;
          for(int j=base-s[i-1];j<=base+s[i-1];j++)
              if(f[pre][j]){ 
                   f[cur][j+i]=true;
                   f[cur][j-i]=true;
                   if(j+i==m+base || j-i==m+base){
                        cout<<i<<endl;
                        return;               
                   }     
              }         
     }
}
int main()
{
    init(); 
    getv();
    system("pause");
    return 0;
}
