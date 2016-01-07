#include<iostream>
using namespace std;
int main()
{
     int m,n,i,j,k,num[101][101];
     scanf("%d %d",&m,&n);
     for(i=0;i<m;i++)
       for(j=0;j<n;j++)
         scanf("%d",&num[i][j]);
     for(i=1;i<m;i++)
       for(j=1;j<n;j++)
       {
            int max=-5000000;
            for(k=i-1;k<j;k++)
              if(max<num[i-1][k])
                max=num[i-1][k];
           num[i][j]=max+num[i][j];                
       }
     int max=-5000000;
     for(k=m-1;k<n;k++)
     {
           if(num[m-1][k]>max)   
                max=num[m-1][k];           
     }
     printf("%d\n",max);
    system("pause");
    return 0;
}
