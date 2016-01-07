#include <iostream>
using namespace std;
const int base=100000;
bool f[500][200100];
int s[500],m;
void init(){
    s[0]=0;
    for(int i=1;i<500;i++) s[i]=s[i-1]+i;
}
void getv(){
    cin>>m;
     f[0][base]=true;
     for(int i=1;i<=500;i++){
          for(int j=base-s[i-1];j<=base+s[i-1];j++)
              if(f[i-1][j]){ 
                   f[i][j+i]=true;
                   f[i][j-i]=true;
                   if(j+i==m+base || j-i==m-base){
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
