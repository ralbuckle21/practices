#include<iostream>
using namespace std;
int mg[100000][6];
void com(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int k=0;
            while(mg[i][k]==mg[j][k])
               k++;
            if(k==6)
            {
                 cout<<"Twin snowflakes found."<<endl;
                 return;
            }  
        }       
    } 
     cout<<"No two snowflakes are alike."<<endl;  
}
int main()
{
    int n;
    int ex[6];
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int min,k=0,xu=0;
         cin>>ex[0];
         min=ex[0];
         for(int h=1;h<6;h++)
         {  
               cin>>ex[h];
               if(min>ex[h])
               {
                    min=ex[h];
                    k=h;
               }
         }
         if(ex[(k-1+6)%6]<ex[(k+1+6)%6])
              xu=1;
         if(xu==0)
            for(int j=0;j<6;j++)
              mg[i][j]=ex[(k+j)%6];  
         else if(xu==1)
            for(int j=0;j<6;j++)
               mg[i][j]=ex[(k+6-j)%6];            
    }
    com(n);
    return 0;
}
