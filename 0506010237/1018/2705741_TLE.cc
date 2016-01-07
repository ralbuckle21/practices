#include<iostream>
using namespace std;
typedef struct
{
      int len;
      int num[101][2];      
}node;
node mg[101];
float maxs=0.0;
int n;
void getresult(int k,int min,int sum)
{
    if(k==n)
    {
        float result=float(min)/float(sum);
        if(result>maxs)  
          maxs=result;    
        return;  
    }
    else
    {
         int mins,sums;
         for(int i=0;i<mg[k].len;i++)
         {     
              mins=(mg[k].num[i][0]<min?mg[k].num[i][0]:min);  
              sums=sum+mg[k].num[i][1];
              getresult(k+1,mins,sums);
         }    
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d",&n);
         maxs=0;
         for(int i=0;i<n;i++)
         {
              scanf("%d",&mg[i].len);
              for(int j=0;j<mg[i].len;j++)
                  scanf("%d %d",&mg[i].num[j][0],&mg[i].num[j][1]);        
         }        
         getresult(0,1000000,0);
         printf("%.3f\n",maxs);
    }
    system("pause");
    return 0;
}
