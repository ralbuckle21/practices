#include<iostream>
using namespace std;
int result(int h)
{
     int left,total=1;
      int k=0;
      while(true)
      {
         total=(2*k+1)*2;
         while(total<=h)
         {
            if(total==h)
              return total/(2*k+1);
            total=2*total;               
         }
         k++;
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
