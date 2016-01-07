#include<iostream>
using namespace std;
int n;
char mg[550];
int num[550];
int main()
{
    while(true){
        memset(mg,NULL,sizeof(mg));
        memset(num,0,sizeof(num));
        scanf("%s",mg+1); 
        if(mg[1]=='0') break;
        mg[0]=mg[1];           
        n=strlen(mg);
        num[0]=1;
        num[1]=1;
        for(int i=2;i<n;i++){
             if(mg[i]=='0') num[i]=num[i-2];
             else if((mg[i-1]-'0')*10+mg[i]-'0'>26 || mg[i-1]=='0') num[i]=num[i-1];
             else num[i]=num[i-2]+num[i-1];        
        }        
        printf("%d\n",num[n-1]);
    }
    system("pause");
    return 0;
}
