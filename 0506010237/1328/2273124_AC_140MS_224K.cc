#include<iostream>
#include<math.h>
using namespace std;
int partion(double c[1000][2],int left,int right)
{
   int i=left,j=right;
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
    return j;
}
void quick(double c[1000][2],int left,int right)
{
   if(left<right)
    {
        int j=partion(c,left,right);
         quick(c,left,j-1);
         quick(c,j+1,right);            
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
        quick(p,0,length-1);
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
    int c[1000];
    int count1=0;
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
           c[count1]=addlist(p,t,r);
           count1++;
       }              
    }
    for(int k=0;k<count1;k++)
     cout<<"Case "<<k+1<<": "<<c[k]<<endl;
   return 0;
}
