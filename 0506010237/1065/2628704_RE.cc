#include<iostream>
using namespace std;
typedef struct
{
    int l,w,sign;        
}node;
char partion(node c[5000],int left,int right)
{
    int i=left;
    int j=right;
    do{
           i++;
         while(c[i].l<c[left].l || (c[i].l==c[left].l && c[i].w<c[left].w))
              i++;
         while(c[j].l>c[left].l || (c[j].l==c[left].l && c[j].w>c[left].w))
              j--;
         if(i<j)
         {
             node temp=c[i];
             c[i]=c[j];
             c[j]=temp;       
         }
         if(i>=j)
         {
             node temp=c[left];
             c[left]=c[j];
             c[j]=temp;        
             return j;
         }
      }while(true);    
}
void quicksort(node c[5000],int left,int right)
{
     if(left<right)
     {
        int mid=partion(c,left,right);
         quicksort(c,left,mid-1); 
          quicksort(c,mid+1,right);            
     }
}
int main()
{
    int t,n,i,j,k,count;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        node num[n];
        for(j=0;j<n;j++)
        {
           scanf("%d %d",&num[j].l,&num[j].w);
           num[j].sign=0;
        }
        quicksort(num,0,n-1);                
        k=0;
        count=0;
        while(k<n)
        {
            j=0;
            int a=-1;
            while(k<n && j<n)
            {
                if(num[j].sign==0 && num[j].w>=a)
                {  
                   a=num[j].w;
                   num[j].sign=1;
                   k++; 
                }             
                j++;
            }       
            count++;     
        }
        cout<<count<<endl;                            
    }
    system("pause");
    return 0;
}
