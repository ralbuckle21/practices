#include <iostream>
using namespace std;
#define MAX 30050                      
int p[MAX], sum[MAX],les[MAX];       
void init()
{                                          
    for (int i = 0; i < MAX; i++)
    {
        p[i] = i;    sum[i]=1;    les[i]=0;
    }
}  
void link(int x, int y)
{                           
      p[y] = x;    
      les[y]=sum[x];    
      sum[x]+=sum[y];   
}
int getles(int top,int c){                      
    if(p[c]!=top){
      les[c]+=getles(top,p[c]);            
               p[c]=top;                                       
    }
    return les[c];
}

int find_set(int d)
{                    
     int t=p[d];
     if(d!=p[d])
     {
         t=find_set(p[d]);
         getles(t,d);                       
     }
     return p[d];                        
}
void union_set(int x, int y)
{               
   link(find_set(x),find_set(y));
}
int main(){
    int p,x,y;
    char op;
    cin>>p;                   
    init();
    while(p--){
          cin>>op;           
          switch(op)
          {
               case 'M':               
                   cin>>x;
                   cin>>y;
                   union_set(x,y);           
                   break;
               case 'C':
                   cin>>x;
                   cout<<sum[find_set(x)]-les[x]-1<<endl;        
                   break;
          }
     }
    return 0;
}