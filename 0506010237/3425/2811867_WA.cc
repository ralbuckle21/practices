#include <iostream>
using namespace std;
typedef struct
{
    int c;
    int sum;
    int k;       
}node;
int main()
{
    int n,x,y,z,j;
	while(scanf("%d",&n)!=EOF)
    {
        node mg[n];
        for(int i=0;i<n;i++)
        {
             scanf("%d %d %d",&x,&y,&z);
             mg[i].sum=0;
             mg[i].c=-1;
             for(j=0;j<i;j++)
                if(mg[j].c==x)
                  break;
            if(j!=i)
            {
                if(y==0)
                   mg[j].sum=mg[j].sum+10;
                else if(y==1 && z==0)
                {
                    mg[j].sum=mg[j].sum+20;
                    mg[j].k++;    
                }
                else if(y==1 && z==1)
                {
                    mg[j].sum=mg[j].sum+40+mg[j].k*10;
                    mg[j].k++;     
                }        
            }
            else if(i==j)
            {
                mg[i].c=x;
                if(y==0)
                   mg[i].sum=10;
                else if(y==1 && z==0)
                {
                    mg[i].sum=20;
                    mg[i].k=1;    
                }
                else if(y==1 && z==1)
                {
                    mg[i].sum=40;
                    mg[i].k=1;     
                } 
            }         
        }
        int f=0;
        for(int i=0;i<n;i++)
          f=mg[i].sum+f;
        printf("%d\n",f);
	}
    system("pause");
	return 0;
}
