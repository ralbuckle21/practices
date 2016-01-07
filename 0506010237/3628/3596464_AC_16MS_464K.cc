#include<iostream>
using namespace std;
int mins=1000000000;
int n,b;
int h[20];
void find(int k,int sum){
    if(k==n){
        if(sum>=b && sum<mins) mins=sum;
        return;
    }
    if(sum>=mins) return;
    find(k+1,sum+h[k]);
    find(k+1,sum);     
}
int main()
{
    scanf("%d %d",&n,&b);
    for(int i=0;i<n;i++) scanf("%d",&h[i]);
    find(0,0);
    cout<<mins-b<<endl;
    system("pause");
    return 0;
}
