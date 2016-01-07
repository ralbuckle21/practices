#include<iostream>
#include<math.h>
using namespace std;
bool visit[65536]={false};
struct{
     bool v[4][4];
     int c;   
}stack[100000];
int front=-1,rear=0;
char mg[5][5];
int getvalue(int x){
    int s=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            s=s*2+stack[x].v[i][j];
    return s;   
}
void find(){
    while(front<rear){
           front=(front+1)%100000;
           int vs=getvalue(front);
           if(visit[vs]) continue;
           if(vs==0 || vs==65535){
                printf("%d\n",stack[front].c);
                return;         
           }
           visit[vs]=true;
           for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                     rear=(rear+1)%100000;
                     stack[rear]=stack[front];
                     stack[rear].c=stack[front].c+1;
                     stack[rear].v[i][j]=!stack[front].v[i][j];
                     if(i>0) stack[rear].v[i-1][j]=!stack[front].v[i-1][j];
                     if(i<3) stack[rear].v[i+1][j]=!stack[front].v[i+1][j];
                     if(j>0) stack[rear].v[i][j-1]=!stack[front].v[i][j-1];
                     if(j<3) stack[rear].v[i][j+1]=!stack[front].v[i][j+1];   
                }           
           }           
    }  
    printf("Impossible\n");   
}
int main()
{
    for(int i=0;i<4;i++){
        scanf("%s",mg[i]);
        for(int j=0;j<4;j++)
            if(mg[i][j]=='b') stack[rear].v[i][j]=0;
            else stack[rear].v[i][j]=1;
    }
    stack[rear].c=0;
    find();
    system("pause");
    return 0;
}
