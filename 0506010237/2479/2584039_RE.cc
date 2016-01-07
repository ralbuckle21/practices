#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct 
{
    int pre;
    int max;       
}node;
void out(int mg[50002],int k)
{
    int pre1=1,pre2=1,h=1,w=k,min=0,max=0;   
    node getmax1[5002],getmax2[5002];
    while(h<=k && mg[h]<=0)h++;
    while(w>=1 && mg[w]<=0)w--;
    while(h<=k)
    {
        while(h<=k && mg[h]>=0)
        {
            min=min+mg[h];  
            h++;
        }
        getmax1[pre1].max=min;
        getmax1[pre1++].pre=h-1;
        while(h<=k && mg[h]<=0)
        {
            min=min+mg[h];
            h++;           
        }      
        if(min<=0)
          min=0;
    }
    min=0;
    while(w>=1)
    {
        while(w>=1 && mg[w]>=0)
        {
            min=min+mg[w];  
            w--;
        }
        getmax2[pre2].max=min;
        getmax2[pre2++].pre=w+1;
        while(w>=1 && mg[w]<=0)
        {
            min=min+mg[w];
            w--;           
        }      
        if(min<=0)
          min=0;
    }
    for(int i=1;i<pre1-1;i++)
    {
        int p=1;
        while(getmax1[i].pre<getmax2[p].pre)
         p++;
        if(max<getmax1[i].max+getmax2[p-1].max)
          max=getmax1[i].max+getmax2[p-1].max;        
    }  
    cout<<max<<endl;
}
int main()
{
    int n,k,x=0,j=1,h=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    { 
       scanf("%d",&k);
       int mg[k+1];
       for(j=1;j<=k;j++)
        scanf("%d",&mg[j]);
       out(mg,k);     
    }
    system("pause");
    return 0;
}
