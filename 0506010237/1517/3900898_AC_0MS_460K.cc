#include <iostream>
#include <iomanip>
using namespace std;
double f[11];
int r[11][11];
int rank[11];
void init(){
     int v;
     f[0]=1; f[1]=2; rank[1]=1;
     for(int i=2;i<=9;i++) rank[i]=rank[i-1]*i;
     for(int i=2;i<=9;i++){
           v=0;
           for(int j=2;j<=i;j++) v += rank[i]/rank[j];
           f[i] = (double)v/(double)rank[i];
           f[i] += 2;     
     }     
}
int main()
{
    init();
    cout<<"n e"<<endl;
    cout<<"- -----------"<<endl;
    for(int i=0;i<=9;i++) cout<<i<<" "<<setprecision(10)<<f[i]<<endl;
    system("pause");
    return 0;
}
