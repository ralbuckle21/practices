#include<iostream>
using namespace std;
typedef struct
{
     int v;
     long long int h;
     int pre;   
}node;
long long int sum=0;
int main()
{
    int n;
    scanf("%d",&n);
    node mg[n];
    for(int i=n-1;i>=0;i--)
    {
           cin>>mg[i].h;
           mg[i].v=0; 
    }
    mg[0].pre=-1;
    for(int i=1;i<n;i++)
    {
        int k=i-1;
        while(k>=0 && mg[i].h>mg[k].h)
        {
            mg[i].v=mg[i].v+1+mg[k].v;
            k=mg[k].pre;           
        }        
        mg[i].pre=k;
        sum=sum+mg[i].v;
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}
