#include<iostream>
#include<string>
using namespace std;
/* int quicksort(int c[1000],int left,int right)
{
        int k=left;
        int i,j;
        i=left+1;
        j=right;
        while(true)
        {
           while(c[i]<c[k])
              i++;
           while(c[j]>c[k])
              j++;
           if(i<j)
           {
              int temp=c[i];
              c[i]=c[j];
              c[j]=temp;       
           }        
           if(i>=j)
           {
             int temp=c[j];
             c[j]=c[k];
             c[k]=temp;
              return j;        
           }
        }
}
void sort(int c[1000],int left,int right)
{
     if(left<right)
     {
         int t=quicksort(c,left,right);
         sort(c,left,t-1);
         sort(c,t+1,right);     
     }    
}
*/
void sort(int c[1000],int n)
{
    for(int i=0;i<n-1;i++)
    {
       for(int j=0;j<n-1-i;j++)
       {
           if(c[j]>c[j+1])
           {
              int l=c[j];
              c[j]=c[j+1];
              c[j+1]=l;               
           }        
       }        
    }    
}
float zhunzhi(int c[1000],int left,int right)
{
      int num=0;
      for(int i=left;i<=right;i++)
          num=num+c[i];        
      return num/(right-left+1);
} 
int main()
{
   int n,k,banduan=0;
   int count=1;
   while(true)
   {
   cin>>n;
   cin>>k;
   if(n==0 && k==0)
     break;
   int c[1000];
   char name[81];
   int zu=n/k;
   for(int i=0;i<n;i++)
   {
      cin>>name;
      c[i]=strlen(name);             
   }  
  // sort(c,0,n-1); 
  sort(c,n);
   for(int j=0;j<zu;j++)
   {
           if(banduan==1)
              break;
      float h=zhunzhi(c,j*k,(j+1)*k-1);
      for(int i=0;i<k;i++)
      {
          if(float(c[j*k+i]-2)>h || float(c[j*k+i]+2)<h)
           {
               banduan=1;
               break;                    
           }        
      }        
   }
   if(banduan==1)
     cout<<"Case "<<count<<": no"<<endl;
   else
     cout<<"Case "<<count<<": yes"<<endl;
    count++;  
    banduan=0;         
   }
     return 0; 
}
