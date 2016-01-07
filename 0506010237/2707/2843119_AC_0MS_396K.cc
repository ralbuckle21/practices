#include<iostream>
using namespace std;
double a,b,c,d;
int main()
{
    while(true)
    {
        cin>>a>>b>>c>>d;
        if(a==0 && b==0 && c==0 && d==0)
          break;
        double x=(c/a)<(d/b)?(c/a):(d/b);
        double y=(d/a)<(c/b)?(d/a):(c/b);
        double sum=x>y?x:y;
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
