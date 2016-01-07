#include<iostream>
#include<math.h>
using namespace std;
/*   1*2*3*..*n=10^b b=b1+b2+...bn
     1*2*3*..*n=10^b1*10^b2...*10^bn
*/
double result[10000002];
int len=0,t;
int find(int n){
    if(n<=len) return int(result[n])+1;
    for(int i=len+1;i<=n;i++)
         result[i]=result[i-1]+log10(i);        
    len=n;
    return int(result[n])+1;
}
int main()
{
    int n;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       printf("%d\n",find(n));
    }
    system("pause");
    return 0;
}


