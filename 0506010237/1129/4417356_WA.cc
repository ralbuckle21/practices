#include<iostream>
using namespace std;
int x[30],cn,n,bestn;
bool mg[30][30];
void init(){
     memset(mg,0,sizeof(mg));
     memset(x,0,sizeof(x));
     cn=0; bestn=0;
}
void backtrace(int k){
    if(k==n) {
        if(cn>bestn) {
            bestn=cn;
            cn=0;                  
        }         
    }    
    else{
        int ok=1;
        for(int i=0;i<k;i++){
           if(x[i]==1 && mg[i][k]==0) {
               ok=0;
               break;           
           }    
        }
        if(ok){
           x[k]=1;
           cn++;
           backtrace(k+1);
           cn--; 
        }
        if(cn+n-(k+1)>bestn){
            x[k]=0;
            backtrace(k+1);                    
        }
    }
}
int main(){
    char s[30]; 
    int len,y;
    while(true){
        scanf("%d",&n);
        if(n==0)break;
        init();
        for(int i=0;i<n;i++){
           scanf("%s",s);
           len=strlen(s);
           for(int j=2;j<len;j++){
                y=s[j]-'A';
                mg[i][y]=true;      
           }
        }
        backtrace(0);
        if(bestn==1) printf("%d channel needed.\n",bestn);
        else printf("%d channels needed.\n",bestn);
    }
    system("pause");
    return 0;
}
