#include<iostream>
using namespace std;
typedef struct{
    int a;
    int b;   
    int sign;    
}node;
node vote[50000];
int n,k;
int cmp(const void *a,const void *b){
     return (*(node *)b).a-(*(node *)a).a;    
}
int main()
{
     scanf("%d %d",&n,&k);
     for(int i=0;i<n;i++){
              scanf("%d %d",&vote[i].a,&vote[i].b);
              vote[i].sign=i+1;
     }
     qsort(vote,n,sizeof(vote[0]),cmp);
     int mins=0,u;
     for(int i=0;i<k;i++) 
          if(vote[i].b>mins){
                 mins=vote[i].b;
                 u=vote[i].sign;
          }
     printf("%d\n",u);
     system("pause");
     return 0;
}
