#include<iostream>
using namespace std;
int cmp(const void *a, const void *b)
{
       return(*(int *)b-*(int *)a);
}
int main()
{
    int n,m,i,j,k,h,c=1;
    while(true)
    {
        scanf("%d %d",&m,&n);
        if(m==0 && n==0)
          break;
        int mg[n+1],mg1[n],sum=n*m;
        for(i=0;i<n;i++)
           scanf("%d",&mg[i]);
        mg[n]=0;
        qsort(mg,n,sizeof(mg[0]),cmp);
        k=0;
        h=0;  
        while(h<n)
        {
            if(mg[k]==sum) 
              k++;
            else
            {
               mg1[h]=sum;
               h++;
            }            
            sum--;
        }
        h=0;
        int result=0;
       for(j=0;j<n;j++)
       {
           if(mg[j]>mg1[h])
             result++;               
           else
             h++;                
       } 
       cout<<"Case "<<c<<": "<<result<<endl; 
       c++;        
    }
    system("pause");
    return 0;
}
