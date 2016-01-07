#include<iostream>
using namespace std;
int result(int h)
{
     int left,k=0,total=1;
     for(int m=1;;m++)
     {
        for(int i=1;i<=m;i++)
           total=2*total;
        int c=total*(2*k+1); 
        while(c<=h)
        {
             if(c==h)
                 return total;
             k++;   
             c=c+2*total;                    
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
       int left=1;
        left=h+1-result(h);
        int right=2*h-left;
        cout<<left<<" "<<right<<endl;
    }   
    return 0;
}