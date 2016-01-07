#include<iostream>
using namespace std;
int result(int h)
{
     int left,k=0,total=1;
     for(int m=1;;m++)
     {
        for(int i=1;i<=m;i++)
           total=2*total; 
        while(total*(2*k+1)<=h)
        {
             if(total*(2*k+1)==h)
                 return m;
             k++;                       
        }  
        k=0;  
        total=1;       
     }   
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
       int h;
       cin>>h;
       int m=result(h);
       int left=1;
       for(int i=1;i<=m;i++)
           left=left*2;
        left=h+1-left;
        cout<<left<<" "<<2*h-left<<endl;
    }   
    return 0;
}
