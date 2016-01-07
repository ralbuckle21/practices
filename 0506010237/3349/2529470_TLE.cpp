#include<iostream>
using namespace std;
int mg[100000][7];
int main()
{
    int n,result=0;
    int ex[6];
    cin>>n;
    for(int i=0;i<n;i++)
    {
         for(int h=0;h<6;h++)
            cin>>ex[h];
         if(result==1)
           continue;
         int min,k=0,xu=0,j;
         mg[i][6]=min=ex[0];
         for(j=1;j<6;j++)
         {
             if(min>ex[j])
             {
                 min=ex[j];
                 k=j;             
             }
             else if(min==ex[j])
             {
                 int p1=ex[(k+5)%6]<=ex[(k+7)%6]?ex[(k+5)%6]:ex[(k+7)%6];
                 int p2=ex[(j+5)%6]<=ex[(j+7)%6]?ex[(j+5)%6]:ex[(j+7)%6];
                 if(p2<p1)
                    j=k;
             }
             mg[i][6]=ex[j]+mg[i][6];
         }
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
             if(mg[w][6]==mg[i][6])
             {
                int c=0;
                while(mg[i][c]==mg[w][c] && c<6)
                c++;
                if(c==6)
                {
                   cout<<"Twin snowflakes found."<<endl;
                   result=1;
                }                         
             } 
             if(result==1)
               break; 
         }          
    }
    if(result==0)
       cout<<"No two snowflakes are alike."<<endl;
    return 0;
}