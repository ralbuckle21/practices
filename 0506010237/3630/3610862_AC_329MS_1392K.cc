#include<iostream>
using namespace std;
typedef struct{
     char name[100];
     int len;       
}node;
node mg[10000];
int n,t;
bool find(){
    for(int i=0;i<n-1;i++){
          int j=0;
          while(j<mg[i].len && mg[i].name[j]==mg[i+1].name[j]) j++;                   
          if(j==mg[i].len) return true;
    }     
    return false;
}
int cmp(const void *a,const void *b){
    return strcmp((*(node *)a).name,(*(node *)b).name);    
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
             scanf("%s",&mg[i].name);
             mg[i].len=strlen(mg[i].name);        
        }      
        qsort(mg,n,sizeof(mg[0]),cmp);    
        if(find()) printf("NO\n");
        else printf("YES\n");
    }
    system("pause");
    return 0;
}
