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
    int n,x,y,z,j,t;
	while(scanf("%d",&n)!=EOF)
    {
        node mg[n];
        t=0;
        for(int i=0;i<n;i++)
        {
             scanf("%d %d %d",&x,&y,&z);
             for(j=0;j<t;j++)
                if(mg[j].c==x)
                  break;
            if(j!=t)
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
            else if(j==t)
            {
                mg[t].c=x;
                if(y==0)
                   mg[t].sum=10;
                else if(y==1 && z==0)
                {
                    mg[t].sum=20;
                    mg[t].k=1;    
                }
                else if(y==1 && z==1)
                {
                    mg[t].sum=40;
                    mg[t].k=1;     
                } 
                t++;
            }         
        }
        int f=0;
        for(int i=0;i<t;i++)
          f=mg[i].sum+f;
        printf("%d\n",f);
	}
    system("pause");
	return 0;
}
