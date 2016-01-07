#include<iostream>
using namespace std;
int mg[11];
int q(int m,int n)
{
    if(m==1 || n==1)
      return 1;
    int count=1,k,h=0;
    mg[0]=m;
    while(mg[0]>=mg[1])
    {
        k=n-1;                     
        while(mg[k]>mg[k-1]-2 && k>1)
           k--;         
        while(mg[k]<=mg[k-1]-2 && k>=1)
        {
           while(mg[k]<=mg[k-1]-2)
           {
              mg[k]++;
              mg[k-1]--;
              count++;   
              h=1;                     
           }
           while(mg[k]>mg[k+1]+2)
           {
               mg[k]--;
               mg[k-1]++;                      
           }
           k--;
        }
        if(h==0)
         break;
        h=0;                     
    }
    return count;  
}
int main()
{
    int c,i,j;
    scanf("%d",&c);
    for(i=1;i<=c;i++)
    {
       int m,n;
       scanf("%d %d",&m,&n);
       for(j=0;j<n;j++)
          mg[j]=0;
       cout<<q(m,n)<<endl;
    }
    system("pause");
    return 0;
}
