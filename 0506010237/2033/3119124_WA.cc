#include<iostream>
#include<string>
using namespace std;
int n;
char mg[50000];
int binaryfind(int left,int right)
{
     if(left>=right || (left+1==right && mg[right]=='0'))
        return 1;
     int mid=(left+right)/2;
     if(mg[mid+1]=='0')
          return binaryfind(left,mid-1)*binaryfind(mid+2,right);               
     else
     {
          if(mg[mid]!='0' && (mg[mid]-'0')*10+mg[mid+1]-'0'<=26)
             return binaryfind(left,mid-1)*binaryfind(mid+2,right)+binaryfind(left,mid)*binaryfind(mid+1,right);
          return  binaryfind(left,mid)*binaryfind(mid+1,right);
     }
}
int main()
{
    scanf("%s",mg);
    while(mg[0]!='0')
    {
        n=strlen(mg);
        printf("%d\n",binaryfind(0,n-1));
       // memset(mg,NULL,5000);
        scanf("%s",mg);               
    }
    system("pause");
    return 0;
}
