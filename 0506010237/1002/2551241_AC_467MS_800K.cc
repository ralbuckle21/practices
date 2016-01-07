#include<iostream>
#include<string>
#include <stdio.h>
#include<iomanip>
using namespace std;
    int num[10][100000];
    int counts[10];
int fg=0;
int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
} 
void out(int k)
{
    int i=1,l=num[k][0];
    int m=counts[k];
    for(int j=1;j<=m;j++)
    {
        if(num[k][j]==l)
           i++;
        else
        {
            if(i!=1)
            {
              cout<<setfill('0')<<setw(3)<<l/10000<<"-"<<setfill('0')<<setw(4)<<l%10000<<" "<<i<<endl;
              fg++;
            }
            i=1;
            l=num[k][j];  
        } 
    }   
    if(i!=1)
    {
       cout<<setfill('0')<<setw(3)<<l/10000<<"-"<<setfill('0')<<setw(4)<<l%10000<<" "<<i<<endl;
       fg++;
    }
}
int main()
{
     int n;
     scanf("%d",&n);
     if(n==1)
          cout<<"No duplicates. "<<endl;  
     for(int i=0;i<=9;i++)
        counts[i]=-1;
    for(int i=0;i<n;i++)
    {
         char ch[100];
         scanf("%s",&ch);
         int m=strlen(ch),k=-1,h=0;
         for(int j=0;j<m;j++)
         {
            int l=-1;
           	if (ch[j] >= '0' && ch[j] <= '9')
        	       l=ch[j]-'0';
		    else if (ch[j] >= 'A' && ch[j] <= 'Y')
			  l=(int) ((ch[j] < 'Q' ? ch[j] - 'A' : ch[j] - 'B') / 3 + '2'-'0');
			if(l!=-1)
            {
                if(k==-1)      
                   k=l; 
                h=h*10+l; 
            }    
         }  
         counts[k]++; 
         num[k][counts[k]]=h;  
    } 
    for(int i=0;i<=9;i++) 
    {
          qsort(num[i],counts[i]+1,sizeof(num[i][0]),cmp);
          out(i);
     }   
     if(fg==0)
       cout<<"No duplicates. "<<endl;  
    system("pause");
    return 0;
}