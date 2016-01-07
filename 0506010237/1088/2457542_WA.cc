#include<iostream>
using namespace std;
int huaxue(int flag[100][100],int mg[100][100],int row,int col,int n,int m)
{
     int k=0;  
     if(m==0 && n==0)
     {
         if(mg[n][m]<mg[n+1][m] && mg[n][m]<mg[n][m+1])
         {
             flag[n][m]=1;
             return 1;    
         }       
     }     
     if(n>0 && mg[n][m]>mg[n-1][m])
     {
         if(flag[n-1][m]==0)
         {
           int t=huaxue(flag,mg,row,col,n-1,m)+1;
           if(k<t)
             k=t;    
         }        
         else if(k<flag[n-1][m]+1)
            k=flag[n-1][m]+1;    
     }
     if(m>0 && mg[n][m]>mg[n][m-1])
     {
         if(flag[n][m-1]==0)
         {
            int t=huaxue(flag,mg,row,col,n,m-1)+1;
            if(k<t)
              k=t;    
         }        
         else if(k<flag[n][m-1]+1)
            k=flag[n][m-1]+1;    
     }
     if(n<row && mg[n][m]>mg[n+1][m])
     {    
          int t=huaxue(flag,mg,row,col,n+1,m)+1;
          if(k<t)
             k=t;
     }
     if(m<col && mg[n][m]>mg[n][m+1])
     {
          int t=huaxue(flag,mg,row,col,n,m+1)+1;
          if(k<t)
            k=t;   
     }  
     flag[n][m]=k;  
     return k;      
}
int main()
{
    int row,col;
    int max=0;
    cin>>row;
    cin>>col;
    int mg[100][100];
    int flag[100][100];
    for(int i=0;i<row;i++)
     {
       for(int j=0;j<col;j++)
       {
            flag[i][j]=0;    
       }        
     }
    for(int i=0;i<row;i++)
    {
       for(int j=0;j<col;j++)
       {
            cin>>mg[i][j];    
       }        
    }        
    for(int i=0;i<row;i++)
    {
       for(int j=0;j<col;j++)
       {
            int temp=huaxue(flag,mg,row,col,i,j);
            if(temp>max)
              max=temp;   
       }        
    }  
    cout<<max<<endl;
    return 0;
}