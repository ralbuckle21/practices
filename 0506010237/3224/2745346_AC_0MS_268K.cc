#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int mg[n][n],count[n];
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<n;j++)
          scanf("%d",&mg[i][j]);
       count[i]=0;
    }
    for(int i=0;i<n;i++)
       for(int j=0;j<n;j++)
         if(mg[i][j]>mg[j][i])
           count[i]++;
    int max=count[0];
    int k=0;
    for(int i=1;i<n;i++)
      if(count[i]>max)
      {
          max=count[i];
          k=i;                
      }
    printf("%d\n",k+1);
    system("pause");
    return 0;
}
