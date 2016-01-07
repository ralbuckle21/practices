#include<iostream>
using namespace std;
typedef struct 
{
	float x,y;
}pointt;
typedef struct
{
    float k;
    float b;  
}node;
node num[490001];
int h=0;
void getresult(pointt p1,pointt p2)
{
      num[h].k=(float)((p2.y-p1.y)/(p2.x-p1.x));
      num[h].b=p1.y-num[h].k*p1.x;
      h++;    
}
int partion(int left,int right)
{
    int i=left;
    int j=right;
    do{
           i++;
         while(num[i].k<num[left].k || (num[i].k==num[left].k && num[i].b<=num[left].b))
              i++;
         while(num[j].k>num[left].k || (num[j].k==num[left].k && num[j].b>num[left].b))
              j--;
         if(i<j)
         {
             node temp=num[i];
             num[i]=num[j];
             num[j]=temp;       
         }
         if(i>=j)
         {
             node temp=num[left];
             num[left]=num[j];
             num[j]=temp;        
             return j;
         }
      }while(true);    
}
void quicksort(int left,int right)
{
     if(left<right)
     {
        int mid=partion(left,right);
        quicksort(left,mid-1); 
        quicksort(mid+1,right);            
     }
}
int main()
{
    int n,total=2,c=0;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)
          break;
        pointt mg[n];
        for(int i=0;i<n;i++)
         scanf("%f %f",&mg[i].x,&mg[i].y); 
        for(int i=0;i<n;i++)
          for(int j=i+1;j<n;j++)
               getresult(mg[i],mg[j]);
        quicksort(0,h-1);
        int i=0;
        int f=h-1; 
        while(i<f)
        {
            int p=i;
            while(i<f && num[p].k==num[i].k && num[p].b==num[i].b)
            {
              c++;
              i++;
            }
            if(c>total)
              total=c;    
            c=0;  
            i++;    
        }      
        printf("%d\n",total);   
        h=0;
        total=2;
    }
    system("pause");
    return 0;
}
