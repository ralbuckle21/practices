#include<iostream>
using namespace std;
float a,b,c,d;
float mins(float x,float y)
{
      return x<y?x:y;  
}
float maxs(float x,float y)
{
      return x>y?x:y;     
}
int main()
{
    while(true)
    {
        scanf("%f %f %f %f",&a,&b,&c,&d);
        if(a==0 && b==0)
          break;
        float sum=maxs(mins(c/a,d/b),mins(d/a,c/b));
        sum=int(sum*100);
        if(sum>100)
          sum=100;
        cout<<sum<<"%"<<endl;          
    }
    system("pause");
    return 0;
}
