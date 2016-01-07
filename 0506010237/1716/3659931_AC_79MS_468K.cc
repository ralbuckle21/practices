#include<iostream>
using namespace std;
typedef struct{
      int s;
      int d;
      int v;
      int sign;  
}node;
node num[10000];
int n;
int cmp1(const void *a,const void *b){
     return (*(node *)a).d-(*(node *)b).d;   
}
int main()
{
     scanf("%d",&n);
     for(int i=0;i<n;i++){ 
          scanf("%d %d",&num[i].s,&num[i].d);   
          num[i].v=0;
     }
     qsort(num,n,sizeof(num[0]),cmp1);
     int len=0;
     for(int i=0;i<n;i++){
         while(num[i].v<2){
               int g=num[i].d+num[i].v-1;
               len++;
               for(int j=i;j<n;j++)
                    if(num[j].s<=g) 
                        num[j].v++;
         }
     }
     printf("%d\n",len);
     system("pause");
     return 0;
}
