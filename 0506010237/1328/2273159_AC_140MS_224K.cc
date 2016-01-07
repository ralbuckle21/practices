#include<iostream>
#include<math.h>
using namespace std;
void partion(double c[1000][2],int left,int right)
{
   int i=left,j=right;
   if(left<right)
   {
      while(true)
      {
         i++;
         while(c[i][0]>c[left][0])
          i++;
          while(c[j][0]<c[left][0])
           j--;
          if(i<j)
          {
            swap(c[i][0],c[j][0]);
            swap(c[i][1],c[j][1]);
           }
          if(i>=j)
          {
             swap(c[left][0],c[j][0]);
             swap(c[left][1],c[j][1]);
             break;
          }
      }    
       partion(c,left,j-1);
       partion(c,j+1,right);              
   }
}
int addlist(double p[1000][2],int length,int r)
{
    int x,y;
    int panduan=0;
     for(int i=0;i<length;i++)
     {
        cin>>x;
        cin>>y;
        if(y>r)
          panduan=1;
        if(panduan==0)
        {
            p[i][0]=x-sqrt(r*r-y*y);
            p[i][1]=x+sqrt(r*r-y*y);
        }
     }
     if(panduan==1)
        return -1;
        partion(p,0,length-1);
    int count=length;
    int i=0;
    int k=0;
    while(i<length-1)
    {
       while(p[i+1][1]>=p[k][0])
       {  
         if(i>= length-1)
           break;               
          i++;
          count--;
       }
       i++;
       k=i;
    }
    return count;
}
int main()
{
    int t,r;
    int count1=1;
    while(true)
    {
       double p[1000][2]; 
       cin>>t;
       cin>>r;
       if(t==0 && r==0)
       {
           break;        
       }
       else
       {
           cout<<"Case "<<count1++<<": "<<addlist(p,t,r)<<endl;
       }              
    }
   return 0;
}