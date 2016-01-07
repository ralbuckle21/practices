#include<iostream>
#include<string>
using namespace std;
struct
{
   char dna[51];
   int count;    
}node[100];
void insertsort(int n,int m)
{
     int i;           
     char c[51];
     for(int w=0;w<n;w++)
     {
        for(int j=0;j<m;j++)
          c[j]=node[w].dna[j];
        node[w].count=0;
        for(int j=1;j<m;j++)
        {
           i=j-1;
           char key=c[j];
           while(i>=0 && c[i]>key)
           {
               c[i+1]=c[i];   
               i--;   
               node[w].count++;
           }       
           c[i+1]=key;
        }  
     } 
}
int main()
{
    int n,m;
    cin>>m;
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>node[i].dna;
    insertsort(n,m);
    //cout<<"*************"<<endl;
    while(true)
    {
        int min=1000000,k=-1;
        for(int i=0;i<n;i++)
           if(node[i].count<min)
           {
                min=node[i].count;
                k=i;               
           }         
           if(min==1000000)
                 break;
           cout<<node[k].dna<<endl;
           node[k].count=1000000;
    }
    system("pause");
    return 0;
}

