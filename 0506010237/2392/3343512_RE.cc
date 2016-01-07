#include<iostream>
using namespace std;
struct node
{
     int c;
     int h;
     int a; 
}block[5001];
int n,maxs=0,len=1;
int cmp(void const *a,void const *b)
{
     return (*(node *)a).a-(*(node *)b).a;   
}
int main()
{
    scanf("%d",&n);
    block[0].a=block[0].c=block[0].h=0;
    for(int i=1;i<=n;i++)
    {
         scanf("%d %d %d",&block[len].h,&block[len].a,&block[len].c);
		 int k=len;
		 len++;
		 for(int j=1;j<block[k].c;j++) block[len++]=block[k];
         if(block[k].a>maxs) maxs=block[k].a;        
    }
	int f[len+2][maxs+3];
	memset(f,0,sizeof(f));
    qsort(block,len,sizeof(block[0]),cmp);
    for(int i=1;i<len;i++)
    {
           for(int j=1;j<=maxs;j++)
           {
                if(j>=block[i].h && j>=f[i-1][j-block[i].h]+block[i].h && f[i-1][j-block[i].h]+block[i].h<=block[i].a && f[i-1][j-block[i].h]+block[i].h>f[i-1][j]) 
                    f[i][j]=f[i-1][j-block[i].h]+block[i].h;
                else
                     f[i][j]=f[i-1][j];   
           }        
     }
    printf("%d\n",f[len-1][maxs]);
    system("pause");
    return 0;
}

