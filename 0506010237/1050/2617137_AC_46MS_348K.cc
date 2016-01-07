#include<iostream>
using namespace std;
int main()
{
    int n,i,j,k,l,result=-10000000;
    scanf("%d",&n);
    int mg[100][100];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        scanf("%d",&mg[i][j]);
    for(i=0;i<n;i++)
     for(j=i;j<n;j++)
     {
       int s[100];
        for(k=0;k<n;k++)
          s[k]=0;
        for(l=i;l<=j;l++)
          s[0]=mg[l][0]+s[0];
        if(s[0]>result)
          result=s[0];  
        for(k=1;k<n;k++)
        {
            for(l=i;l<=j;l++)
              s[k]=mg[l][k]+s[k];
            if(s[k-1]>0)
              s[k]=s[k]+s[k-1];
            if(s[k]>result)
               result=s[k];              
        } 
     }   
     cout<<result<<endl;                         
    system("pause");
    return 0;
}
