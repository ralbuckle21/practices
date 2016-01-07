#include<iostream>
using namespace std;
int num[100000];
int m,t,u,f,d;
int v[256];
int main()
{
     char c;
     scanf("%d %d %d %d %d",&m,&t,&u,&f,&d);
     v['u']=u; v['f']=f; v['d']=d;
     v['u']=v['u']+v['d']; v['f']=2*v['f'];v['d']=v['u'];
     for(int i=0;i<t;i++){ 
         scanf(" %c",&c);
         num[i]=v[c];
     }
     int i=0;
     while(m>=num[i]){
         m=m-num[i];
         i++;                 
     }
     printf("%d\n",i);
     system("pause");
     return 0;
}
