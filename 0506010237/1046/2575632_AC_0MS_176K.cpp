#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
typedef struct 
{
    int x;
    int y;
    int z;
}node;
node color[16]; 
int h=0;
int mg[500];
int main()
{
    for(int i=0;i<16;i++)
      scanf("%d %d %d",&color[i].x,&color[i].y,&color[i].z);
    int x,y,z,min=10000000,d,k=0;
    while(true)
    {
        scanf("%d %d %d",&x,&y,&z);
        if(x==-1 && y==-1 && z==-1)   
           break;
        for(int i=0;i<16;i++)
        {
             d=(color[i].x-x)*(color[i].x-x)+(color[i].y-y)*(color[i].y-y)+(color[i].z-z)*(color[i].z-z);
             if(min>d)
             {
                   min=d;
                   k=i;
             }       
        }        
        printf("%c%d%c%d%c%d%c %s %c%d%c%d%c%d%c\n",'(',x,',',y,',',z,')',"maps to",'(',color[k].x,',',color[k].y,',',color[k].z,')');
        min=10000000;
    }
    system("pause");
    return 0;
}
