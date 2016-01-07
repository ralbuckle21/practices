#include<iostream>
using namespace std;
char c[10000];
int n;
int main(){
    while(true){
        scanf("%s",c);
        if(c[0]=='0') break;
        int s=0; n=strlen(c);
        for(int i=0;i<n;i++){
              s+=c[i]-'0';
              if(s>10) s=s/10+s%10;        
        }
        cout<<s<<endl;            
    }
    system("pause");
    return 0;
}
