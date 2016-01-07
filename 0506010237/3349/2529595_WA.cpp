#include<iostream>
using namespace std;
int mg[100000][7];
void com(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(mg[j][6]==mg[i][6])
            {
                  for(int k=0;k<6;k++)
                  {
                      int kw=0,w=0;
                      while(mg[i][k]!=mg[j][w] && w<6)
                           w++;
                      while(kw<6 && mg[i][(k+6)%6]==mg[j][(w+6)%6])
                      {
                          k++;
                          w++;  
                          kw++;     
                       } 
                      if(kw==6)
                      {
                         cout<<"Twin snowflakes found."<<endl;
                           return;
                       }
                  }       
            }  
        }       
    } 
     cout<<"No two snowflakes are alike."<<endl;  
}
int main()
{
    int n;
    int ex[7];
    cin>>n;
    for(int i=0;i<n;i++)
    {
         int min,k=0,xu=0;
         cin>>ex[0];
         ex[6]=0;
         for(int h=1;h<6;h++)
         {  
               cin>>ex[h];
               ex[6]=ex[6]+ex[h];
         }                    
    }
    com(n);
    return 0;
}
