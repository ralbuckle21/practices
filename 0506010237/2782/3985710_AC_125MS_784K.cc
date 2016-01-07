#include<iostream>
using namespace std;
int h[100000];
int n,w;
int cmp(const void *a,const void *b){
    return *(int *)b-*(int *)a;    
}
int main(){
    int c=0,i,j;
    scanf("%d%d",&n,&w);
    for(i=0;i<n;i++)  scanf("%d",&h[i]);        
    qsort(h,n,sizeof(h[0]),cmp);
    i=0;j=n-1;
    while(i<j){
         if(h[i]+h[j]<=w){ i++;j--;}
         else i++;
         c++;   
    }
    if(i==j) c++;
    cout<<c<<endl;
    system("pause");
    return 0;
}
