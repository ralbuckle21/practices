#include<iostream>
using namespace std;
int n;
int num[500]={0};
int len=0,k=0;
int main()
{
    scanf("%d",&n);
    if(n==0){
        cout<<0<<endl;
        return 0;         
    } 
    if(n<0){
        n=-n;
        while(n){
             num[len++]=n%2;
             n=n/2;        
        }   
        for(int i=0;i<len;i=i+2){
             if(num[i]==1){
                 int j=i+1;
                 num[j]++;
                 while(num[j]==2){
                     num[j]=0;
                     num[++j]++;                 
                 }     
                 if(j>k) k=j;
                 if(k>=len) len=k+1;         
             }    
        }
    }
    else{
        while(n){
             num[len++]=n%2;
             n=n/2;        
        }        
        for(int i=1;i<len;i=i+2){
             if(num[i]==1){
                 int j=i+1;
                 num[j]++;
                 while(num[j]==2){
                     num[j]=0;
                     num[++j]++;                 
                 }
                 if(j>k) k=j; 
                 if(k>=len) len=k+1;             
             }       
        }   
    }
    for(int i=len-1;i>=0;i--) printf("%d",num[i]);
    printf("\n");
    system("pause");
    return 0;
}
