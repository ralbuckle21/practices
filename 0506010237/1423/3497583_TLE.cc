#include<iostream>
#include<math.h>
/*   1*2*3*..*n=10^b b=b1+b2+...bn
     1*2*3*..*n=10^b1*10^b2...*10^bn
*/
using namespace std;
int main()
{
    double b=0;
    int a,i,n,t;
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       for(i=1;i<=n;i++)
           b+=log10(i);
       a=(int)b;
       printf("%d\n",a+1);
       b=0;
    }
    system("pause");
    return 0;
}
