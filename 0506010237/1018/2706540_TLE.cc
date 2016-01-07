#include<iostream>
using namespace std;
typedef struct
{
      int len;
      int num[101][2];  
      int sign[101];    
}node;
node mg[101];
float maxs=0.0;
int n;
int partion(int row,int left,int right)
{
    int i=left;
    int j=right;
    do{
           i++;
         while(mg[row].num[i][0]>mg[row].num[left][0] || (mg[row].num[i][0]==mg[row].num[left][0]) && mg[row].num[i][1]<mg[row].num[left][1])
              i++;
         while(mg[row].num[j][0]<mg[row].num[left][0] || (mg[row].num[j][0]==mg[row].num[left][0]) && mg[row].num[i][1]>mg[row].num[left][1])
              j--;
         if(i<j)
         {
             int temp=mg[row].num[i][0];
             int temp1=mg[row].num[i][1];
             mg[row].num[i][0]=mg[row].num[j][0];
             mg[row].num[i][1]=mg[row].num[j][1];
             mg[row].num[j][0]=temp;
             mg[row].num[j][1]=temp1;       
         }
         if(i>=j)
         {
             int temp=mg[row].num[left][0];
             int temp1=mg[row].num[left][1];
             mg[row].num[left][0]=mg[row].num[j][0];
             mg[row].num[left][1]=mg[row].num[j][1];
             mg[row].num[j][0]=temp;
             mg[row].num[j][1]=temp1;         
             return j;
         }
      }while(true);    
}
void quicksort(int row,int left,int right)
{
     if(left<right)
     {
        int mid=partion(row,left,right);
         quicksort(row,left,mid-1); 
          quicksort(row,mid+1,right);            
     }
}
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
               if(mg[k].sign[i]==0)
               {
                  mins=(mg[k].num[i][0]<min?mg[k].num[i][0]:min);  
                  sums=sum+mg[k].num[i][1];
                  getresult(k+1,mins,sums);
               }
         }    
    }
}
void chuli(int row,int len)
{
     int i=1,pre=0;
     while(i<len)
     {
             if(mg[row].num[i][1]>=mg[row].num[pre][1])
                  mg[row].sign[i]=1;
             else
                pre=i;
             i++;            
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
              {
                  scanf("%d %d",&mg[i].num[j][0],&mg[i].num[j][1]);
                  mg[i].sign[j]=0;
              } 
              quicksort(i,0,mg[i].len-1);
              chuli(i,mg[i].len);
         }    
         getresult(0,1000000,0);
         printf("%.3f\n",maxs);
    }
    system("pause");
    return 0;
}
