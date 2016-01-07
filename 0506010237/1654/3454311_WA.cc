#include<iostream>
#include<math.h>
using namespace std;
int sign[10][2];
char c[1000002];
int t;
void init(){
    sign[8][0]=0,sign[8][1]=1;
    sign[9][0]=1,sign[9][1]=1;
    sign[6][0]=1,sign[6][1]=0;
    sign[3][0]=1,sign[3][1]=-1;
    sign[2][0]=0,sign[2][1]=-1;
    sign[1][0]=-1,sign[1][1]=-1;
    sign[4][0]=-1,sign[4][1]=0;
    sign[7][0]=-1,sign[7][1]=1;     
}
int main()
{
    init();
    scanf("%d",&t);
    while(t--){
         double area=0.0;
         scanf("%s",c);
         int i=0;
         long long int x=0,y=0,x1,y1;
         while(c[i]!='5'){
               x1=x+sign[c[i]-'0'][0];
               y1=y+sign[c[i]-'0'][1];
               area+=x*y1-x1*y;   
               x=x1,y=y1;
               i++;         
         }
         cout<<fabs(area/2)<<endl;         
    }
    system("pause");
    return 0;
}
