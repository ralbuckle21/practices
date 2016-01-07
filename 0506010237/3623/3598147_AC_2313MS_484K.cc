#include<iostream>
using namespace std;
char c[30001];
char d[30001];
bool minleft(int x,int y){
      while(x<y){
           if(c[x]<c[y]) return true;
           else if(c[x]>c[y]) return false;
           else{
               x++;
               y--;     
           }            
      }    
      return true;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)  cin>>c[i];        
    int i=0,j=n-1,t=0;
    while(i<=j){
        if(c[i]<c[j]){
            d[t++]=c[i];
            i++;              
        }       
        else if(c[i]>c[j]){
             d[t++]=c[j];
             j--;     
        }       
        else{
              if(minleft(i+1,j-1)){
                  d[t++]=c[i];
                  i++;
              }
              else{
                  d[t++]=c[j];
                  j--;     
              }
        }
    }
    for(i=0;i<n;i++){
        if(i>0 && i%80==0) printf("\n");
        printf("%c",d[i]);        
    }
    printf("\n");
    system("pause");
    return 0;
}

