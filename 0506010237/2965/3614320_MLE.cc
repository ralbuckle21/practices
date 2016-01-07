#include<iostream>
#include<math.h>
using namespace std;
bool visit[65536]={false};
struct{
     bool v[4][4];
     int c;   
     int num[30][2];
}stack[500000];
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
           front=(front+1)%500000;
           int vs=getvalue(front);
           if(visit[vs]) continue;
           if(vs==0){
                printf("%d\n",stack[front].c);
                for(int k=0;k<stack[front].c;k++)
                   printf("%d %d\n",stack[front].num[k][0],stack[front].num[k][1]);
                return;         
           }
           visit[vs]=true;
           for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                     rear=(rear+1)%500000;
                     stack[rear]=stack[front];
                     stack[rear].c=stack[front].c+1;
                     stack[rear].num[stack[rear].c-1][0]=i+1;
                     stack[rear].num[stack[rear].c-1][1]=j+1;
                     stack[rear].v[i][j]=!stack[front].v[i][j];
                     for(int k=0;k<4;k++){
                         stack[rear].v[i][k]=!stack[front].v[i][k]; 
                         stack[rear].v[k][j]=!stack[front].v[k][j]; 
                     }     
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
            if(mg[i][j]=='-') stack[rear].v[i][j]=0;
            else stack[rear].v[i][j]=1;
    }
    stack[rear].c=0;
    find();
    system("pause");
    return 0;
}
