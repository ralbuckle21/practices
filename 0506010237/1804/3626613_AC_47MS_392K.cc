#include<iostream>
using namespace std;
int t,n,k=1;
int num[1000];
int main()
{
    scanf("%d",&t);
    while(k<=t){
        printf("Scenario #%d:\n",k++);
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&num[i]);
        int sum=0;
        for(int i=0;i<n;i++) 
            for(int j=i+1;j<n;j++)
                if(num[i]>num[j]) sum++;
        printf("%d\n\n",sum);          
    }
    system("pause");
    return 0;
}
