#include<iostream>
using namespace std;
typedef struct
{
      int len;
      int num[101][2];  
      int sign[101];    
}node;
node mg[101];
int n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
         int mf[10001];
         int k=0;     
         scanf("%d",&n);
         for(int i=0;i<n;i++)
         {
              scanf("%d",&mg[i].len);
              for(int j=0;j<mg[i].len;j++)
              {
                  scanf("%d %d",&mg[i].num[j][0],&mg[i].num[j][1]);
                  mf[k++]=mg[i].num[j][0];
              } 
         }    
         float maxs=0.0;
         for(int i=0;i<k;i++)
         {
              int sum=0;
              for(int j=0;j<n;j++)
              {
                   int min=100000;
                   for(int h=0;h<mg[j].len;h++)
                       if(mg[j].num[h][0]>=mf[i] && mg[j].num[h][1]<min)
                          min=mg[j].num[h][1];
                   sum=sum+min;
              }        
              if(float(mf[i])/float(sum)>maxs)
                maxs=float(mf[i])/float(sum);
         }
         printf("%.3f\n",maxs);
    }
    system("pause");
    return 0;
}
