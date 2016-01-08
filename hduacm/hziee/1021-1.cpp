#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
        if(n<2)printf("no\n");
        else if((n-2)%4) 
            printf("no\n");
        else
            printf("yes\n");
    return 0;
}
