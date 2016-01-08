#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 3001
int a[MAX];
int cmp ( const void *a,const void *b ) 
{ 
     return *(int *)b - *(int *)a; 
} 

int main()
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        memset(a, 0, sizeof(a));
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        if(n == 1)
        {
            printf("Jolly\n");
            continue;
        }
        for(i=1; i<n; i++)
            a[i-1]=abs(a[i]-a[i-1]);
        a[n-1]=0;
        qsort(a,MAX,sizeof(a[0]),cmp);
        for(i=0;i<=n-2;i++)
            if(a[i]!=n-i-1)
                break;
        if(i==n-1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");    
    }
}