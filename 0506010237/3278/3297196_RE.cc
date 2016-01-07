#include<iostream>
using namespace std;
bool visit[200000]={0};
struct 
{
   int x;
   int min;      
}mg[200000000];
int front=-1,rear=-1;
int n,k;
void find()
{
   mg[++rear].x=n;
   mg[rear].min=0;
   visit[n]=1;
   while(front<rear)
   {
        front++;
        if(mg[front].x==k)
        {
              printf("%d\n",mg[front].min); 
              return;                 
        }            
        if(!visit[2*mg[front].x] && mg[front].x<=2*k/3)
        {
             visit[2*mg[front].x]=1;
             rear++;
             mg[rear].x=mg[front].x*2;
             mg[rear].min=mg[front].min+1;             
        }  
        if(!visit[mg[front].x+1] && mg[front].x<k)
        {
             visit[mg[front].x+1]=1;
             rear++;
             mg[rear].x=mg[front].x+1;
             mg[rear].min=mg[front].min+1;               
        }
        if(!visit[mg[front].x-1] && mg[front].x>1)
        {
             visit[mg[front].x-1]=1;
             rear++;
             mg[rear].x=mg[front].x-1;
             mg[rear].min=mg[front].min+1;               
        }   
   }    
}
int main()
{
     scanf("%d %d",&n,&k);
     find();
     system("pause");
     return 0;
}
