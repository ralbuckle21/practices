#include<iostream>
#include<string>
using namespace std;
struct 
{
   char s[17];
   int money;      
}node[1000];
int main()
{
   int m,n;
   cin>>m;
   cin>>n;
   char ch;
   for(int i=0;i<m;i++)
   {
       cin>>node[i].s;   
       cin>>node[i].money;     
   }
   for(int i=0;i<n;i++)
   {  
       char word[30];
       int j=0;
       int total=0;
       cin.get(ch);
       while(ch!='.')
       {
            if(ch!=' ' && ch!='\n')
             { 
               word[j++]=ch;
               cin.get(ch);  
             }
            else if(ch==' ' || ch=='\n')
            {
                word[j]='\0';
                  cin.get(ch); 
                  while(ch==' ' || ch=='\n')
                     cin.get(ch);
                for(int k=0;k<m;k++)
                {
                   if(strcmp(word,node[k].s)==0)
                   {
                       total=total+node[k].money;
                       break;                             
                   }     
                }
                j=0;    
            }            
       }   
       cout<<total<<endl;     
   }
   return 0;
}
