#include<iostream>
using namespace std;
char mg[5002];
short num[5000][5000];
short mins(int x,int y)
{
    return x<=y?x:y;     
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",mg);
    for(int i=0;i<n;i++)
      num[i][i]=0;
    for(int i=1;i<n;i++)
    {
        int k=0;
        for(int j=i;j<n;j++)
        {
            num[k][j]=num[k+1][j-1]+2;
            if(mg[k]==mg[j])
               num[k][j]=num[k+1][j-1];
            num[k][j]=mins(mins(num[k][j],num[k+1][j]+1),num[k][j-1]+1);
            k++;        
        }        
    } 
    printf("%d\n",num[0][n-1]);
    system("pause");
    return 0;
}
