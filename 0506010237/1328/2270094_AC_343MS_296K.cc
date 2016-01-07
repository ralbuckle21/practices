#include<iostream>
#include<math.h>
using namespace std;
int partion(double c[1000][4],int left,int right)
{
   int i=left,j=right;
   while(true)
    {
         i++;
         while(c[i][2]>c[left][2])
          i++;
          while(c[j][2]<c[left][2])
           j--;
          if(i<j)
          {
            swap(c[i][0],c[j][0]);
            swap(c[i][1],c[j][1]);
            swap(c[i][2],c[j][2]);
            swap(c[i][3],c[j][3]);
           }
          if(i>=j)
          {
             swap(c[left][0],c[j][0]);
             swap(c[left][1],c[j][1]);
             swap(c[left][2],c[j][2]);
             swap(c[left][3],c[j][3]);
             break;
          }
    }    
    return j;
}
void quick(double c[1000][4],int left,int right)
{
   if(left<right)
    {
        int j=partion(c,left,right);
         quick(c,left,j-1);
         quick(c,j+1,right);            
     }        
}
int addlist(double p[1000][4],int length,int r)
{
    int panduan=0;
     for(int i=0;i<length;i++)
     {
        cin>>p[i][0];
        cin>>p[i][1];
        if(p[i][1]>r)
          panduan=1;
        if(panduan==0)
        {
            p[i][2]=p[i][0]-sqrt(r*r-p[i][1]*p[i][1]);
            p[i][3]=p[i][0]+sqrt(r*r-p[i][1]*p[i][1]);
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
       while(p[i+1][3]>=p[k][2])
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
       double p[1000][4]; 
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
     system("PAUSE");
   return 0;
}