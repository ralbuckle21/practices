#include<iostream>
using namespace std;
int main()
{
    int n;
    while(true)
    {
          cin>>n;
          if(n==0)
            break;
          else
          {
             int count,count1=0;
             int max=0;
             int min=1001;
             for(int i=0;i<n;i++)
             {
                 cin>>count;
                 if(count<min)
                    min=count;
                 if(count>max)
                    max=count;
                    count1=count1+count;
             }      
             count1=count1-max-min;
             count1=count1/(n-2);
             cout<<count1<<endl;
          }    
    }    
    return 0;
}

