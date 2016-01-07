#include<iostream>
#include<string>
using namespace std;
char mg[62],mgd[62];  
int len,sign=0;    
void muls(int k)
{
        int c=0;
        for(int i=len-1;i>=0;i--)
        {
              c=(mg[i]-'0')*k+c;
              mgd[i]=c%10+'0';
              c=c/10; 
        }       
        if(c>0) sign=1;
} 
bool cmp()
{
     int i=0,j=0;
     while(i<len)
     {
         int x=i;
         while(j<len && mgd[x]==mg[j])
         {
                x=(x+1)%len;
                j++;                   
         }      
         if(j==len) return 1;
         else
         {
              i++;
              j=0;    
         }     
     }
     return false;  
}
int main()
{
     while(scanf("%s",mg)!=EOF)
     {
        len=strlen(mg);
         for(int i=1;i<=len;i++)
         {
            muls(i);
            if(!cmp())
            {
                 sign=1;
                 break;                    
            }
         }         
         if(sign) printf("%s is not cyclic\n",mg);
         else printf("%s is cyclic\n",mg); 
         sign=0;                
     }
     system("pause");
     return 0;
}
