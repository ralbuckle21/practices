/*#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct point
{
    int x,y,z,s;
};
int a[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int main()
{
    int l,r,c;
    while(cin>>l>>r>>c)
    {
        if(l==0||r==0||c==0) break;
        char temp;
        int res=99999;
        bool p[32][32][32]={false};
        point st,ed,ts,tp;
        for(int i=1;i<=l;i++)
            for(int j=1;j<=r;j++)
                for(int k=1;k<=c;k++)
                {
                    cin>>temp;
                    if(temp=='.') p[i][j][k]=true;
                    else if(temp=='S')
                    {
                        st.x=i;
                        st.y=j;
                        st.z=k;
                        st.s=0;
                        p[i][j][k]=true;
                    }
                    else if(temp=='E')
                    {
                        ed.x=i;
                        ed.y=j;
                        ed.z=k;
                        ed.s=99999;
                        p[i][j][k]=true;
                    }
                }
        queue<point> q;
        q.push(st);
        while(!q.empty())
        {
            ts=q.front();
            if(ts.x==ed.x&&ts.y==ed.y&&ts.z==ed.z)
            {
                cout<<"Escaped in "<<ts.s<<" minute(s)."<<endl;
                break;
            }
            else
            {
                for(int i=0;i<6;i++)
                {
                    tp.x=ts.x+a[i][0];
                    tp.y=ts.y+a[i][1];
                    tp.z=ts.z+a[i][2];
                    tp.s=ts.s;
                    if(p[tp.x][tp.y][tp.z])
                    {
                        p[tp.x][tp.y][tp.z]=false;
                        tp.s++;
                        q.push(tp);
                    }
                }
            }
            q.pop();
        }
        if(q.empty()) cout<<"Trapped!"<<endl;
    }
}*/

#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct point
{
    int x,y,z,s;
};
int a[6][3]={{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int main()
{
    int l,r,c;
    while(cin>>l>>r>>c)
    {
        if(l==0||r==0||c==0) break;
        char temp;
        int res=99999;
        bool p[32][32][32]={false};
        point st,ed,ts,tp;
        for(int i=1;i<=l;i++)
            for(int j=1;j<=r;j++)
                for(int k=1;k<=c;k++)
                {
                    cin>>temp;
                    if(temp=='.') p[i][j][k]=true;
                    else if(temp=='S')
                    {
                        st.x=i;
                        st.y=j;
                        st.z=k;
                        st.s=0;
                        p[i][j][k]=true;
                    }
                    else if(temp=='E')
                    {
                        ed.x=i;
                        ed.y=j;
                        ed.z=k;
                        ed.s=99999;
                        p[i][j][k]=true;
                    }
                }
        queue<point> q;
        q.push(st);
        while(!q.empty())
        {
            ts=q.front();
            if(ts.x==ed.x&&ts.y==ed.y&&ts.z==ed.z)
            {
                cout<<"Got the answer in "<<ts.s<<" minutes!"<<endl;
                break;
            }
            else
            {
                for(int i=0;i<6;i++)
                {
                    tp.x=ts.x+a[i][0];
                    tp.y=ts.y+a[i][1];
                    tp.z=ts.z+a[i][2];
                    tp.s=ts.s;
                    if(p[tp.x][tp.y][tp.z])
                    {
                        p[tp.x][tp.y][tp.z]=false;
                        tp.s++;
                        q.push(tp);
                    }
                }
            }
            q.pop();
        }
        if(q.empty()) cout<<"Goddess will fail her final exams."<<endl;
    }
}
