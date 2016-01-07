#include<iostream>
using namespace std;
char c[100],d[100];
int n;
bool visit[256];
int main(){
    memset(visit,0,sizeof(visit));
    visit['A']=true; visit['E']=true; visit['I']=true; visit['O']=true; visit['U']=true;
    gets(c); n=strlen(c);
    int j=0;
    for(int i=0;i<n;i++){
        if(visit[c[i]]) continue;
        if(c[i]<='Z' && c[i]>='A'){
            d[j++]=c[i];       
            visit[c[i]]=true;
        }
        else if(c[i]==' '){
             if(j>0 && d[j-1]!=' ') d[j++]=' ';      
        }
        else{
             if(d[j-1]==' ') j--; 
             d[j++]=c[i];    
        }
    }
    if(d[j-1]==' ') j--;
    for(int i=0;i<j;i++) printf("%c",d[i]);
    printf("\n");
    system("pause");
    return 0;
}
