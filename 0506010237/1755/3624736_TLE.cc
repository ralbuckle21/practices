#include<iostream>
using namespace std;
struct{
      double v,u,w; 
}mg[200];
bool sign[200]={false};
int n;
int main()
{
    scanf("%d",&n);
    int j=0;
    for(int i=0;i<n;i++){ 
            scanf("%lf %lf %lf",&mg[i].v,&mg[i].u,&mg[i].w);
            mg[i].v=1/mg[i].v;
            mg[i].u=1/mg[i].u;
            mg[i].w=1/mg[i].w;
    }
    while(j++<5000000){
        double best = 200000000; 
        int u;
        double x=rand();
        double y=rand();
        double z=rand();
        for(int i=0;i<n;i++) {
            double d=x*mg[i].v+y*mg[i].u+z*mg[i].w;    
            if(d<best){ best=d; u=i;}    
        } 
        sign[u]=true;
    }
    for(int i=0;i<n;i++) if(sign[i]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    system("pause");
    return 0;
}
