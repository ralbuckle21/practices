#include<iostream>
using namespace std;
struct
{
    int i;      
    int j;
    int sign;  
}node[400];
int top=-1;
int main()
{
   while(true)
   {
       int ji,lu;
       int counts=1;
       char mg[20][20];
       int n,m;
       cin>>m;
       cin>>n;
       if(m==0 && n==0)
          break;
       for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         {
             cin>>mg[i][j];
             if(mg[i][j]=='@')
             {
                    ji=i;
                    lu=j;
             }   
         }
         for(int k=-1;k<3;k++)
         {
                 top=0;
                 node[top].sign=k;
                 node[top].i=ji;
                 node[top].j=lu;
          while(top>-1)
          {
             int i,j,find=0;
             int sign=node[top].sign;
             for(int h=0;h<4;h++)
             {
                 sign++;
                 if(sign>=4)
                   break;
                 i=node[top].i;
                 j=node[top].j;
                 switch(sign)
                 {
                    case 0:
                       i--;
                       break;
                    case 1:
                       j++;
                       break;
                    case 2:
                       i++;
                       break;
                    case 3:
                       j--;  
                       break;            
                 }        
                 if(i>=0 && i<n && j>=0 && j<m && mg[i][j]=='.')
                        find=1;
                 if(find==1)
                   break;
             } 
             if(find==1)
             {
                 node[top].sign=sign;
                 top++;
                 node[top].i=i;
                 node[top].j=j;
                 mg[i][j]='*'; 
                 node[top].sign=-1;        
                 counts++;   
             }     
             else if(find==0)
             {
                 top--; 
                     
             }       
           }        
         }
         cout<<counts<<endl;
   }
   system("pause");
   return 0;
}
