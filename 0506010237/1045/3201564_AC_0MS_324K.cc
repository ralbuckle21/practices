#include<iostream>
#include<math.h>
using namespace std;
//vr=vs/sqrt(r*r+1/(w*w*c*c))*r;
float vs,r,c,w,vr;
int n;
int main()
{
     scanf("%f %f %f %d",&vs,&r,&c,&n);
     for(int i=0;i<n;i++)
     {
          scanf("%f",&w);
          vr=vs/sqrt(r*r+1/(w*w*c*c))*r;
          printf("%.3f\n",vr);        
     }
     system("pause");
     return 0;
}
