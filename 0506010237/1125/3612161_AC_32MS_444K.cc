#include<iostream>
using namespace std;
const int maxs=INT_MAX/2;
int mg[100][100];
int n;
void shortpath(){ 
    for(int u=0;u<n;u++)
        for(int v=0;v<n;v++)
            for(int w=0;w<n;w++)
                if(mg[v][w]>mg[v][u]+mg[u][w])
                     mg[v][w]=mg[v][u]+mg[u][w];
    int mins=maxs,u;
    for(int i=0;i<n;i++){
         int ww=0;
         for(int j=0;j<n;j++)
              if(i!=j && mg[i][j]>ww) ww=mg[i][j];       
         if(mins>ww){
              u=i;
              mins=ww;            
         }
    }    
    if(mins==maxs) cout<<"disjoint"<<endl;
    else cout<<u+1<<" "<<mins<<endl; 
}
int main()
{
    int x,k,w;
    while(true){
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                mg[i][j]=maxs;
        for(int i=0;i<n;i++){
             scanf("%d",&x);
             for(int j=0;j<x;j++){
                  scanf("%d %d",&k,&w);
                  mg[i][k-1]=w;        
             }        
        }
        shortpath();
    }
    system("pause");
    return 0;
}
