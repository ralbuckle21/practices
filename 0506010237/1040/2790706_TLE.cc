#include<iostream>
using namespace std;
typedef struct
{
    int start;
    int stop;
    int people;       
}node;
node order[8];
int n,m,max_people,maxs=0,num[8];
void traceback(int t)
{
     if(t==m)
     {
             int sum1=0;
             for(int i=1;i<=n;i++)
               sum1=sum1+num[i];
         if(maxs<sum1)
           maxs=sum1;
         return;          
     }   
     traceback(t+1);
     int i=0;
     for(i=order[t].start+1;i<=order[t].stop;i++)
          if(order[t].people+num[i]>max_people)
            break;
     if(i==order[t].stop+1)
     {
        for(i=order[t].start+1;i<=order[t].stop;i++)
           num[i]=num[i]+order[t].people; 
        traceback(t+1);
     }  
}
int main()
{
    while(true)
    {
        scanf("%d %d %d",&max_people,&n,&m);
        if(max_people==0 && n==0 && m==0)
          break;
        for(int i=0;i<=n;i++)
        {
           num[i]=0;
           order[i].people=0;
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
           scanf("%d %d %d",&order[i].start,&order[i].stop,&order[i].people);
        }
        traceback(0);   
        printf("%d\n",maxs);
        maxs=0;        
    }
    system("pause");
    return 0;
}
