#include<iostream>
using namespace std;
int main()
{
    int num[14]={0,2,7,5,30,169,441,1872,1740,93313,459901,1358657,2504881,13482720};
    int k;
    while(true)
    {
        scanf("%d",&k);
        if(k==0)
           break;
        printf("%d\n",num[k]);           
    }
    system("pause");
    return 0;
}
