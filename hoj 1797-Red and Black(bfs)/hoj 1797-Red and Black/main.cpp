#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct point
{
    int x,y;
};
int main()
{
    int w,h;
	while(cin>>w>>h)
    {
        if(w==0||h==0) return 0;
        bool a[22][22]={false};
        char temp;
        int res=1;
        point p,t;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                cin>>temp;
                if(temp=='.') a[i][j]=true;
                else if(temp=='@')
                {
                    p.x=i;
                    p.y=j;
                }
            }
        }
        queue<point> points;
        points.push(p);
        while(!points.empty())
        {
            p=points.front();
            if(a[p.x+1][p.y]==true)
            {
                t.x=p.x+1;
                t.y=p.y;
                points.push(t);
                a[p.x+1][p.y]=false;
                res++;
            }
            if(a[p.x-1][p.y]==true)
            {
                t.x=p.x-1;
                t.y=p.y;
                points.push(t);
                a[p.x-1][p.y]=false;
                res++;
            }
            if(a[p.x][p.y+1]==true)
            {
                t.x=p.x;
                t.y=p.y+1;
                points.push(t);
                a[p.x][p.y+1]=false;
                res++;
            }
            if(a[p.x][p.y-1]==true)
            {
                t.x=p.x;
                t.y=p.y-1;
                points.push(t);
                a[p.x][p.y-1]=false;
                res++;
            }
            points.pop();
        }
        cout<<res<<endl;
    }
}
