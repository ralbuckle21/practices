#include<iostream>
using namespace std;
bool visit[100000];
int h[100000];
int n,w;
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;    
}
int main(){
    int c=0,i=0;
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++)  scanf("%d",&h[i]);        
    qsort(h,n,sizeof(h[0]),cmp);
    while(true){
         while(i<n && visit[i]) i++;
         if(i>=n) break;
         visit[i]=true; c++;
         int j=i+1;
         while(j<n){
               if(!visit[j] && h[i]+h[j]<=w){
                    visit[j]=true;
                    break;             
               }
               j++;           
         }            
    }
    cout<<c<<endl;
    system("pause");
    return 0;
}
