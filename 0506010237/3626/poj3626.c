#include <stdio.h>

typedef struct {
    int x, y;
}queue;

queue q[1000000];

int m[1005][1005]={0};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int good(int x,int y)
{
    if(x>=0&&x<=1000&&y>=0&&y<=1000&&m[x][y]==0) return 1;
    else return 0;
}

int main()
{
    int ex,ey,n;
    int i,a,b;
    int sx,sy;
    int tx,ty;
    int head,tail;
    scanf("%d%d%d",&ex,&ey,&n);
    ex+=500;
    ey+=500;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        m[a+500][b+500]=1;
    }
    sx=500;sy=500;
    m[sx][sy]=1;
    head=tail=0;
    q[tail].x=sx;
    q[tail].y=sy;
    tail++;

    int find=0;

    while(head<=tail&&find==0)
    {
        for(i=0;i<4;i++)
        {
            tx=q[head].x+dx[i];
            ty=q[head].y+dy[i];
            if(good(tx,ty))
            {
                q[tail].x=tx;
                q[tail].y=ty;
                tail++;
                m[tx][ty]=m[q[head].x][q[head].y]+1;
                if(m[ex][ey]!=0)
                {
                    find=1;
                    break;
                }
            }
        }
        head++;
    }

    printf("%d\n",m[ex][ey]-1);
    getch();

}

