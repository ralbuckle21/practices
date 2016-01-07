#include<iostream>
using namespace std;
int grid(float n,float m)
{
    return int(n)*int(m);
}
int abskew(float n,float m)
{
    int total=0,r,h;
    int k=int(n);
    float w=n-float(k);
    if(w>=0.5)
        r=k;
    else
        r=k-1;
    h=1;
    m=m-1;
    while(m>=0.866)
    {
        m=m-0.866;
        h++;              
    }  
    total=h*r;
    if(w<0.5)
          total=total+(h+1)/2;
    return total;
}
int baskew(float n,float m)
{
    int total=0,r,h;
    int k=int(m);
    float w=m-float(k);
    if(w>=0.5)
        r=k;
    else
        r=k-1;
    h=1;
    n=n-1;
    while(n>=0.866)
    {
        n=n-0.866;
        h++;              
    }  
    total=h*r;
    if(w<0.5)
       total=total+(h+1)/2; 
    return total;
}
int main()
{
    int count1,count2,count3;
    float n,m; 
    while(cin>>n && cin>>m)
    {
      count1=grid(n,m);
      count2=abskew(n,m);
      count3=baskew(n,m);
      if(n<1.0 || m<1.0)
      {
            cout<<"0 grid"<<endl;
            continue;
      }
      if(count1>=count2 && count1>=count3)
         cout<<count1<<" grid"<<endl;
      else if(count2>count1 && count2>count3)
         cout<<count2<<" skew"<<endl;
      else
         cout<<count3<<" skew"<<endl;       
    }
   return 0;
}