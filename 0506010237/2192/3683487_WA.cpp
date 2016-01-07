#include<iostream>
using namespace std;
char a[1500],b[1500],c[1500];
int lena,lenb,lenc;
int t,cs=1;
bool find(int x,int y,int k){
     if(k==lenc) return true;
     if(x<lena && y<lenb && a[x]==b[y]){
          if(a[x]!=c[k]) return false;
          if(x+1<lena && a[x+1]==c[k+1]) return find(x+1,y,k+1);
          else return find(x,y+1,k+1);   
     }
     if(x<lena && a[x]==c[k]) return find(x+1,y,k+1);
     if(y<lenb && b[y]==c[k]) return find(x,y+1,k+1);
     return false;
}
int main()
{
     scanf("%d",&t);
     while(t--){
          scanf("%s %s %s",a,b,c);
          lena=strlen(a); lenb=strlen(b); lenc=strlen(c);
          printf("Data set %d: ",cs++);
          if(find(0,0,0)) printf("yes\n");
          else printf("no\n");     
     }
     system("pause");
     return 0;
}
