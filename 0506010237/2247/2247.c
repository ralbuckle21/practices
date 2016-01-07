#include<stdio.h>
#include<stdlib.h>
int main()
{
    int ham[5842];
    int a[4]={0,0,0,0};
    ham[0] = 1;
    int i;
    for(i = 1; i < 5842; i++)
    {
        int tem1 = 2 * ham[a[0]] > 3* ham[a[1]] ? 3*ham[a[1]]: 2 * ham[a[0]];
        int tem2 = 5 * ham[a[2]] > 7 * ham[a[3]]? 7*ham[a[3]]:5 *ham[a[2]];
        int temp = tem1 > tem2 ? tem2:tem1;
        ham[i] = temp;
        if(ham[i] == 2 * ham[a[0]]) a[0]++;
        if(ham[i] == 3 * ham[a[1]]) a[1]++;
        if(ham[i] == 5 * ham[a[2]]) a[2]++;
        if(ham[i] == 7 * ham[a[3]]) a[3] ++;     
          
    }
    /*for(i = 0; i < 5842; i++)
    printf("%d,",ham[i]);*/
    int n;
    while(scanf("%d",&n),n)
    {
           if(n % 10 == 1 &&n %100!=11)
           printf("The %dst humble number is %d.\n ",n,ham[n-1]);
           else if(n % 10 == 2 && n %100 != 12 )
           printf("The %dnd humble number is %d. \n",n,ham[n-1]);
           else if(n%10 == 3 && n %100!= 13)
           printf("The %drd humble number is %d. \n",n,ham[n -1]);
           else printf("The %dth humble number is %d. \n",n,ham[n -1 ]);                
    }
    system("pause");
    return 0;
    }
 
 
 
