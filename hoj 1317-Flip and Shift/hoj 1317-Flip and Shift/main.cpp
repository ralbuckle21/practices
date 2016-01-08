#include <stdio.h>
#include <math.h>
int main()
{
    int t, n, i, j, arr[2],sum;
    scanf("%d", &t);
    while (t--) 
 {
        scanf("%d",&n);
  arr[0]=0;arr[1]=0;
        for (i=0; i<n;i++)
  {
    scanf("%d", &j);
   if(n&1)
   {
    continue;
   }
   if(i&1)
    arr[0]+=j;
   else
    arr[1]+=j;
       }
       if(n&1)
        printf("YES\n");
    else
    {
     if(fabs(arr[0]-arr[1]+0.0)<=1)
      printf("YES\n");
      else
          printf("NO\n");
    }
    }
    return 0;
}