#include<iostream>
using namespace std;
int n;
bool visit[4];
char a[4],b[4],t,f;
int main()
{
    scanf("%d",&n);
    while(n--){
         memset(visit,0,sizeof(visit));
         scanf("%s %s",a,b);
         t=0;f=0;
         for(int i=0;i<4;i++) 
             if(a[i]==b[i]){
                visit[i]=1;
                t++;
             }
         for(int i=0;i<4;i++)
            for(int j=0;j<4;j++){
                 if(!visit[j] && a[j]==b[i]){
                       visit[j]=1;
                       f++;
                 }
            }
         printf("%dA%dB\n",t,f);           
    }
    system("pause");
    return 0;
}
