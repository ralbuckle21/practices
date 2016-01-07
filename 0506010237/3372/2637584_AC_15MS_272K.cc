#include<iostream>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
          int h=1;
          while(h<n)
            h=h*2;
          if(h==n)
            printf("%s\n","YES");
          else
            printf("%s\n","NO");                            
    }
    system("pause");
    return 0;
}
