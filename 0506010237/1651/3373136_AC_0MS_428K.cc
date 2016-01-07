#include<iostream>
#define maxs INT_MAX
using namespace std;
int n,num[101];
int f[101][101]={0};
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&num[i]);
    for(int h=2;h<n;h++){
        for(int i=1;i<=n;i++){
           int len=h+i;
           if(len>n) break;
           f[i][len]=maxs;
           for(int j=i+1;j<len;j++)
               if(f[i][len]>f[i][j]+f[j][len]+num[i]*num[j]*num[len])
                   f[i][len]=f[i][j]+f[j][len]+num[i]*num[j]*num[len];  
        } 
    }
    printf("%d\n",f[1][n]);
    system("pause");
    return 0;
}
