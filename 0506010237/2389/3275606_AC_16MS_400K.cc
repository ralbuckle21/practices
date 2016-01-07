#include<iostream>
#include<string>
using namespace std;
char first[41];
char second[41];
void nixu(int h,int l)
{
     int low=0,large=h-1;
     char temp;
     while(low<large)
     {
        temp=first[low];
        first[low]=first[large];
        first[large]=temp;
        low++;
        large--;
     }
     low=0;
     large=l-1;
     while(low<large)
     {
        temp=second[low];
        second[low]=second[large];
        second[large]=temp;
        low++;
        large--;
     }
}
void mul(int h,int l)
{
    int third[h+l];
    int g=1;
    for(int f=0;f<h+l;f++)
       third[f]=0;
       int w=0;
   for(int i=0;i<h;i++)
   {
          for(int j=0;j<l;j++)
            {
                  int k=(int(first[i]-48))*(int(second[j]-48));
                  w=(k%10+third[j+i])/10+k/10;
                   third[j+i]=(k%10+third[j+i])%10;
                   while(w)
                   {
                        third[j+i+g]=(w+third[j+i+g]);
                        w=third[j+i+g]/10;
                        third[j+i+g]=third[j+i+g]%10;
                     g++;
                   }
                   g=1;
            }
   }
   int j=h+l-1;
   while(third[j]==0) j--;
   if(j==-1) printf("0\n"); 
   for(;j>=0;j--) printf("%d",third[j]);
   printf("\n");
}
int main()
{
    cin>>first;
    cin>>second;
    int n=strlen(first);
    int m=strlen(second);
    nixu(n,m);
    mul(n,m);
     system("pause");
     return 0;
}

