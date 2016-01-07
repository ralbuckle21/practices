#include<iostream>
using namespace std;
double a,b,c,d;
double mins(double x,double y)
{
      return x<y?x:y;  
}
double maxs(double x,double y)
{
      return x>y?x:y;     
}
int main()
{
    while(true)
    {
        cin>>a>>b>>c>>d;
        if(a==0 && b==0 && c==0 && d==0)
          break;
        double sum=maxs(mins(c/a,d/b),mins(d/a,c/b));
        sum=int(sum*100);
        if(sum>100)
          sum=100;
        else if(sum<1)
          sum=1;
        cout<<sum<<"%"<<endl;          
    }
    system("pause");
    return 0;
}
