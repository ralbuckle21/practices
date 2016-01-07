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
    cin>>n;
    for(int i=0;i<n;i++)
    {
         mg[i][6]=0;
         for(int h=0;h<6;h++)
         {  
               cin>>mg[i][h];
               mg[i][6]=mg[i][6]+mg[i][h];
         } 
    }
    com(n);
    system("pause");
    return 0;
}
