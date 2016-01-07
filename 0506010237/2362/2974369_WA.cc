#include<iostream>
using namespace std;
int num[20];
bool visit[20];
int n,t;
int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
bool find(int left,int k,int value)
{
     int i;
     if(left==0 && k==0)
       return true;
     if(left==0)
        left=value;
     if(left<num[n-1])
        return false;
     for(i=0;i<n;i++)
     {
          if(visit[i]==false && num[i]<=left)
          {
               visit[i]=true;
               if(find(left-num[i],k-1,value));
                  return true;
               visit[i]=false;    
               if(left == value)
                 return false;               
          }                 
     }
     return false;
}
int main()
{
    int value,sum,i;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       sum=0;
       for(i=0;i<n;i++)
       {
            scanf("%d",&num[i]);
            sum=sum+num[i];  
            visit[i]=false;            
       }
       qsort(num, n, sizeof(int), cmp);
       if(sum%4!=0 || num[0]>sum/4)
          printf("no\n");
       else
       {
           value=sum/4;    
           if(find(value,n,value))
              printf("yes\n");
           else
             printf("no\n");
       }
    }
    system("pause");
    return 0;
}

