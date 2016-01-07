#include<iostream>
using namespace std;
struct{
     char v[200];
     int len;   
}f[601];
char a[110],b[110];
int lena,lenb;
void add(int k){
    int len=f[k-1].len+1,i=0;
    int c=0;
    while(i<len){
        f[k].v[i]=f[k-2].v[i]-'0'+f[k-1].v[i]-'0'+c;
        c=f[k].v[i]/10;
        f[k].v[i]=f[k].v[i]%10+'0';
        i++;             
    }
    while(f[k].v[len]=='0') len--;
    f[k].len=len+1;
}
void init(){
     memset(f,'0',sizeof(f));
     f[0].v[0]='1';f[0].len=1;
     f[1].v[0]='1';f[1].len=1;
     for(int i=2;i<601;i++) add(i);    
}
bool strcmpa(int k){
     int i=0;
     if(f[k].len<lena) return false;
     else if(f[k].len>lena) return true;
     while(i<lena){
         if(f[k].v[lena-1-i]>a[i]) return true;
         else if(f[k].v[lena-1-i]<a[i]) return false;
         i++;
     }
     return true;
}
bool strcmpb(int k){
     int i=0;
     if(f[k].len<lenb) return false;
     else if(f[k].len>lenb) return true;
     while(i<lenb){
         if(f[k].v[lenb-i-1]>b[i]) return true;
         else if(f[k].v[lenb-i-1]<b[i]) return false;
         i++;
     }
     return false;
}
int main()
{  
    init();
    while(true){
        scanf("%s %s",a,b);
        if(a[0]=='0' && b[0]=='0') break; 
        lena=strlen(a),lenb=strlen(b);
        int i=0,j;
        while(!strcmpa(i)) i++;
        j=i;
        while(!strcmpb(j)) j++;
        cout<<j-i<<endl;          
    }
    system("pause");
    return 0;
}
