#include<iostream>
using namespace std;
int n,sum=1,k;
int main()
{
    scanf("%d %d",&n,&k);
    int i,j,c=0,x;
    int visit[k+1];
    for(i=1;i<=k;i++)
       visit[i]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(visit[x]==false)
        {
           visit[x]=true;
           c++;                  
        }      
        if(c==k)
        {
            sum++;
            for(int j=1;j<=k;j++)
              visit[j]=false;  
            c=0;      
        }           
    } 
    printf("%d\n",sum);
    system("pause");
    return 0;
}
