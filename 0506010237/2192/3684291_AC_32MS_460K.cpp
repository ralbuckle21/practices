#include<iostream>
using namespace std;
char a[500],b[500],c[500];
int lena,lenb,lenc;
int t,cs=1;
bool list[500][500]; 
bool lcs(){
    memset(list,0,sizeof(list));
    list[0][0]=true;
    for(int i=0;i<lena;i++)
        for(int j=0;j<lenb;j++){
             if(c[i+j]==b[j] && j>0 && list[i][j-1]) list[i][j]=true;
             if(c[i+j]==a[i] && i>0 && list[i-1][j]) list[i][j]=true;        
        }      
    return list[lena-1][lenb-1];
}
int main()
{
     scanf("%d",&t);
     while(t--){
          scanf("%s %s %s",a+1,b+1,c+1);
          a[0]='0'; b[0]='0'; c[0]='0';
          lena=strlen(a); lenb=strlen(b); lenc=strlen(c);
          printf("Data set %d: ",cs++);
          if(lcs()) printf("yes\n");
          else printf("no\n");     
     }
     system("pause");
     return 0;
}
