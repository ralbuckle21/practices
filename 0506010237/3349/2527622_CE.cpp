#include<iostream>
using namespace std;
int mg[100000][6];
int main()
{
    int n,result=0;
    int ex[6];
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int min,k=0,xu=0;
         for(int h=0;h<6;h++)
           cin>>ex[h];
         if(result==1)
           continue;
         min=ex[0];
         for(int j=1;j<6;j++)
             if(min>ex[j])
             {
                 min=ex[j];
                 k=j;             
             }
         if(ex[(k-1+6)%6]<ex[(k+1+6)%6])
              xu=1;
         if(xu==0)
            for(int j=0;j<6;j++)
              mg[i][j]=ex[(k+j)%6];  
         else if(xu==1)
            for(int j=0;j<6;j++)
               mg[i][j]=ex[(k+6-j)%6]; 
         for(int j=0;j<i;j++)
         {
            int c=0;
            while(mg[i][k]==mg[j][k])
               k++;
            if(k==6)
            {
                 cout<<"Twin snowflakes found."<<endl;
                 result=1;
            }  
            if(result==1)
              break;   
         }          
    }
    if(result==0)
       cout<<"No two snowflakes are alike."<<endl;
    return 0;
}
