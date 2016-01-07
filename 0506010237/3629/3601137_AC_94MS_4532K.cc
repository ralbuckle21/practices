#include<iostream>
using namespace std;
int n,k,m,p;
int num[100000];
int len=0;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int stack[1000000];
int front,rear;
int main()
{
    int x=0,j;
    scanf("%d %d %d",&n,&k,&p);
    m=k/n;
    front=0;rear=k-1;
    for(int i=front;i<=rear;i++) stack[i]=i;
    int player=0;
    for(int i=0;i<k;i++){
        if (player == n-1) num[len++]=stack[front]+1;
        player=(player+1)%n;
        front=(front+1)%1000000;              
        for (j = 0; j < p; j++){
            rear=(rear+1)%1000000;
            stack[rear]=stack[front];
            front=(front+1)%1000000;
        }   
    }
    qsort(num,len,sizeof(num[0]),cmp);
    for(int i=0;i<len;i++) printf("%d\n",num[i]);
    system("pause");
    return 0;
}
