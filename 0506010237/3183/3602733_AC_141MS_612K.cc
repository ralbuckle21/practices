#include<iostream>
using namespace std;
int h[50000];
int n;
int main()
{
    int r=1;
    h[0]=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    while(r<=n){
        while(r<=n && h[r]>h[r-1]) r++;
        printf("%d\n",r-1);
        while(r<=n && h[r]<h[r-1]) r++;
        h[r-1]=0;
    }
    system("pause");
    return 0;
}
