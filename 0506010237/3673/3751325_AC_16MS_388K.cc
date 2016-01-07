#include<iostream>
using namespace std;
int a,b;
int numa[100],numb[100];
int lena=0,lenb=0;
int main()
{
     scanf("%d%d",&a,&b);
     while(a){
         numa[lena++]=a%10;
         a=a/10;         
     }
     while(b){
         numb[lenb++]=b%10;
         b=b/10;         
     }
     int sum=0;
     for(int i=0;i<lena;i++)
          for(int j=0;j<lenb;j++)
              sum+=numa[i]*numb[j];
     printf("%d\n",sum);
     system("pause");
     return 0;
}
