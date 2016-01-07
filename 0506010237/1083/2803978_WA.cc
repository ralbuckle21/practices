#include<iostream>
using namespace std;
typedef struct
{
    int start;
    int stop;
    bool visit;       
}node;
int cmp( const void *a ,const void *b)
{
     return ((node *)a)->start> ((node *)b)->start ? 1 : -1;
}
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        node mg[n];
        for(int i=0;i<n;i++)
        {
             scanf("%d %d",&mg[i].start,&mg[i].stop);
             if(mg[i].start>=mg[i].stop)
             {
                 int temp=mg[i].start;
                 mg[i].start=mg[i].stop;
                 mg[i].stop=temp;                           
             }
             mg[i].visit=false;        
        } 
        qsort(mg,n,sizeof(mg[0]),cmp);      
        int sum=0,i=0,k;
        while(i<n)
        {
             while(mg[i].visit==true && i<n)
                i++;
             if(i==n)
                break;
             sum++;
             k=i;
             mg[k].visit=true;
             for(int j=k+1;j<n;j++) 
             {
                 if(mg[j].visit==false && mg[j].start>mg[k].stop)
                 {
                      mg[j].visit=true;
                      k=j;                      
                 }        
             }       
        } 
        printf("%d\n",sum*10);  
    }
    system("pause");
    return 0;
}
