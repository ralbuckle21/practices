#include<iostream>
using namespace std;
void getpm(char mg[51][51],int n,int m)
{
    int pm[51][51],i,j;
    for(i=0;i<=n;i++)
     for(j=0;j<=i;j++)
       pm[i][j]=0;
     pm[0][0]=1;
     if(mg[0][0]=='.')
     {
         pm[2][1]=pm[0][0]*4+pm[2][1];
         pm[0][0]=0;               
     }
    for(i=1;i<=n;i++)
     for(j=0;j<=i;j++)
     {
        if(j==0)
        {
          pm[i][0]=pm[i-1][0]+pm[i][0];
           if(i!=n)
            if(mg[i][0]=='.')
            {
                  pm[i+2][j+1]=pm[i][j]*4+pm[i+2][j+1];
                  pm[i][j]=0;              
            }     
        }
        else if(j==i)
        {
          pm[i][i]=pm[i-1][i-1]+pm[i][i];
            if(i!=n)
            if(mg[i][i]=='.')
            {
                  pm[i+2][j+1]=pm[i][j]*4+pm[i+2][j+1];
                  pm[i][j]=0;             
            }
        }
        else
        {
            pm[i][j]=pm[i-1][j-1]+pm[i-1][j]+pm[i][j];
            if(i!=n)
              if(mg[i][j]=='.')
              {
                  pm[i+2][j+1]=pm[i][j]*4+pm[i+2][j+1];
                  pm[i][j]=0;              
              }     
        }                 
     }
     int w=n,k=1;
     while(pm[n][m]%2==0)
     {
        pm[n][m]=pm[n][m]/2;
        w--;            
        if(pm[n][m]==0)
        {
           cout<<"0/1"<<endl;
           return;               
        }        
     }
     for(i=1;i<=w;i++)
       k=2*k;
     cout<<pm[n][m]<<"/"<<k<<endl;
}
int main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    char mg[51][51];
    for(i=0;i<n;i++)
      for(j=0;j<=i;j++)
       cin>>mg[i][j];
    getpm(mg,n,m);
    system("pause");
    return 0;
}

