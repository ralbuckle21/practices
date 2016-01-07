#include<iostream>
using namespace std;
int num[1000];
int cmp ( const void *a , const void *b )
{
     return *(int *)a - *(int *)b;
}
int main()
{
    int t,n,count,sum=0,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
          scanf("%d",&num[i]);
        if(n==1)
        {
              printf("%d\n",num[0]);
              continue;        
        }
        else if(n==2)
        {
             int k=num[0]>num[1]?num[0]:num[1];
             printf("%d\n",k);
             continue;     
        }
        i=0;
        j=n-1;        
        count=(n-1)/2;
        sum=0;
        qsort(num,n,sizeof(num[0]),cmp); 
        while(i<count)
        {
            sum=sum+num[j];
            j=j-2;
            i++;              
        }
        int c=2*n-3-count;
        int c1=c*3/4;
        sum=sum+c1*num[1]+(c-c1)*num[0];
        printf("%d\n",sum); 
    }
    system("pause");
    return 0;
}
