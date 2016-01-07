#include<iostream>
using namespace std;
int n;
char chess[8][8];
int maxs=0;
bool position(int x,int y,bool sign[8][8])
{
    int i=x-1;
    while(i>=0)
    {
        if(chess[i][y]=='X'){i=-1;break;}
        if(sign[i][y]==true)break;
         i--;           
    } 
    if(i==-1)
    {
         int j=y-1;
         while(j>=0)
         {
            if(chess[x][j]=='X'){j=-1;break;}
            if(sign[x][j]==true) break;
            j--;
         }   
         if(j==-1) return true;      
    }
    return false;
}
void find(int k,int f,bool sign[8][8],int ge)
{
        if(k>=n)
        {
             if(maxs<ge) maxs=ge;
             return;
        }
      if(chess[k][f]=='.' && position(k,f,sign))
        {
              sign[k][f]=true;
              if(f<n-1) find(k,f+1,sign,ge+1);
              else find(k+1,0,sign,ge+1);
              sign[k][f]=false;                
        }
        if(f<n-1) find(k,f+1,sign,ge);
        else find(k+1,0,sign,ge);
}
int main()
{
    while(true)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++)
           scanf("%s",chess[i]);
        bool sign[8][8];
        memset(sign,0,sizeof(sign));
        find(0,0,sign,0);  
        cout<<maxs<<endl;
       maxs=0;        
    }
    system("pause");
    return 0;
}
