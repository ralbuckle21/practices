#include<iostream>
#include<math.h>
using namespace std;
/*   1*2*3*..*n=10^b b=b1+b2+...bn
     1*2*3*..*n=10^b1*10^b2...*10^bn
*/
double result[1000002];
int t;
void find(int n){
    result[0]=0;
    for(int i=1;i<=n;i++)
         result[i]=result[i-1]+log10(double(i));        
}
int main()
{
    int n;
    find(1000000);
    scanf("%d",&t);
    while(t--){
       scanf("%d",&n);
       printf("%d\n",int(result[n])+1);
    }
    system("pause");
    return 0;
}
