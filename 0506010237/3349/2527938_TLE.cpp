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
         cin>>ex[0];
         int k=0,min=ex[0];
         for(int h=1;h<6;h++)
         {
             cin>>ex[h];
             if(min>ex[h])
               {
                    min=ex[h];
                    k=h;
               }
        }
         if(result==1)
           continue;
         int xu=0,j;
         if(ex[(k+5)%6]<ex[(k+7)%6])
              xu=1;
         if(xu==0)
            for(j=0;j<6;j++)
              mg[i][j]=ex[(k+j)%6];  
         else if(xu==1)
            for(j=0;j<6;j++)
               mg[i][j]=ex[(k+6-j)%6]; 
         for(int w=0;w<i;w++)
         {
            int c=0;
            while(mg[i][c]==mg[w][c] && c<6)
               c++;
            if(c==6)
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
