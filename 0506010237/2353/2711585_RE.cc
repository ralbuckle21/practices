#include<iostream>
#include<math.h>
using namespace std;
typedef struct
{
   int prex,prey;
   int v;
   long long int sum;       
}node;
node num[100][500];
int main()
{
     int m,n;
     scanf("%d %d",&m,&n);
     for(int i=0;i<m;i++)
       for(int j=0;j<n;j++)
          scanf("%d",&num[i][j].v);
     for(int i=0;i<n;i++)
     {
          num[0][i].prey=i;
          num[0][i].prex=-1; 
          num[0][i].sum=num[0][i].v;      
     }
    for(int i=1;i<m;i++)
    {
          num[i][0].sum=num[i-1][0].sum+num[i][0].v;
          num[i][0].prey=0;
          num[i][0].prex=i-1; 
       for(int j=1;j<n;j++)
       {
            if(num[i-1][j].sum<=num[i][j-1].sum)
            {
                num[i][j].sum=num[i-1][j].sum+num[i][j].v;
                num[i][j].prey=j;
                num[i][j].prex=i-1;
            }
            else
            {
               num[i][j].sum=num[i][j-1].sum+num[i][j].v;
               num[i][j].prex=i;
               num[i][j].prey=j-1;
            }         
       }
       for(int j=n-2;j>=0;j--)
       {
                if(num[i][j].sum>num[i][j+1].sum+num[i][j].v)
                {
                      num[i][j].sum=num[i][j+1].sum+num[i][j].v;
                      num[i][j].prex=i;
                      num[i][j].prey=j+1;
                }        
       }
    }
    long long int min=num[m-1][0].sum;
    int h=0;
    for(int j=1;j<n;j++)
           if(num[m-1][j].sum<min)
           {
              min=num[m-1][j].sum;
              h=j;
           } 
     int path[5000],x=1,f,g;
     path[0]=h;
     f=num[m-1][h].prex;
     g=num[m-1][h].prey;
     while(f!=-1)
     {     
         path[x++]=g;
         int w=num[f][g].prex;
         g=num[f][g].prey;
         f=w;           
     }     
     for(int i=x-1;i>=0;i--)
       printf("%d\n",path[i]+1);
    system("pause");
    return 0;
}
