#include<iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
     return *(int *)a-*(int *)b;
}
int main()
{
     int n;
     long long int num[10000];
     scanf("%d",&n);
     for(int i=0;i<n;i++)scanf("%d",&num[i]);
     qsort(num,n,sizeof(num[0]),cmp);
     cout<<num[n/2]<<endl;
     system("pause");
     return 0;
}
