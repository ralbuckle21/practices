#include<iostream>
#include<string>
using namespace std;
int t,len1,len2;
char mg[3][40000];
int value[200][200];
void init()
{
     value[0][0]=0;
     value[0]['A']=value['A'][0]=-3;
     value[0]['C']=value['C'][0]=-4;
     value[0]['G']=value['G'][0]=-2;
     value[0]['T']=value['T'][0]=-1;
     value['A']['A']=5;
     value['A']['C']=-1;
     value['A']['G']=-2;
     value['A']['T']=-1;
     value['C']['A']=-1;   
     value['C']['C']=5;
     value['C']['G']=-3;
     value['C']['T']=-2;
     value['G']['A']=-2;
     value['G']['C']=-3;
     value['G']['G']=5;
     value['G']['T']=-2;
     value['T']['A']=-1;
     value['T']['G']=-2;
     value['T']['C']=-2;
     value['T']['T']=5;
}
int main()
{
    init();
    scanf("%d",&t);
    while(t--)
    {
         scanf("%d %s",&len1,mg[0]+1);       
         scanf("%d %s",&len2,mg[1]+1);    
         if(len1>len2)
         {
             strcpy(mg[2]+1,mg[0]+1);
             strcpy(mg[0]+1,mg[1]+1);
             strcpy(mg[1]+1,mg[2]+1);
             int tmp=len2;
             len2=len1;
             len1=tmp;             
         }
         int f[len1+20][len2+20];
         f[0][0]=0;
         for(int i=1;i<=len2;i++) f[0][i]=value[0][int(mg[1][i])]+f[0][i-1];
         for(int j=1;j<=len2;j++)
         for(int i=1;i<=j && i<=len1;i++)
         {
              f[i][j]=f[i-1][j-1]+value[int(mg[0][i])][int(mg[1][j])];
              if(i<j && f[i][j]<f[i][j-1]+value[0][int(mg[1][j])])
                f[i][j]=f[i][j-1]+value[0][int(mg[1][j])];  
         }
         printf("%d\n",f[len1][len2]); 
    }
   system("pause");
   return 0;
}
