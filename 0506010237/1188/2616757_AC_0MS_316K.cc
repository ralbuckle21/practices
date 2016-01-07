#include<iostream>
#define mins -100000000;
#define maxs 100000000;
using namespace std;
int min(int a,int b)
{
    return a<=b?a:b;   
}
int max(int a,int b)
{
    return a>=b?a:b;   
}
int main()
{
    int n,i; 
    while(true)
    {
       scanf("%d",&n);
       if(n==0)
         break;
       int startx=mins;
       int starty=mins;
       int startz=mins;
       int stopx=maxs;
       int stopy=maxs;
       int stopz=maxs;
       int x,y,z,len,h=0; 
       for(i=0;i<n;i++)
       {
           scanf("%d %d %d %d",&x,&y,&z,&len);
           if(h==1)
             continue;   
           startx=max(startx,x);
           starty=max(starty,y);
           startz=max(startz,z);
           x=x+len;
           y=y+len;
           z=z+len;
           stopx=min(stopx,x);
           stopy=min(stopy,y);
           stopz=min(stopz,z);
           if(startx>=stopx || starty>=stopy || startz>=stopz)
              h=1;               
       }
       if(h==0)
       {
           cout<<(stopx-startx)*(stopy-starty)*(stopz-startz)<<endl;        
       }   
       else
         cout<<'0'<<endl;        
    }
    system("pause");
    return 0;
}
